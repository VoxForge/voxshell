###############################################################################
#
#    Copyright (C) 2015  VoxForge
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################

# convert grammar from forward to backward grammar format required by mkfa::
# from: S: NS_B COMMAND NS_E 
# to:   S: NS_E COMMAND NS_B 
function reverse_grammar(rgramfile,gramfile)
  rgramfile_fh=open(rgramfile,"w")

  gramfile_arr=open(readlines, gramfile) # automatically closes file handle 
  n=0
  for lineln=gramfile_arr
    if ! ismatch(r"^[\n|\r]", lineln)
      line=replace(chomp(lineln), r"#.*", "") # remove line endings & comments
      (left, right)=split(line,r"\:")
      category_arr=split(right,r"\s")
      reverse_category_arr=reverse(category_arr)

      write(rgramfile_fh, left * ":")
      write(rgramfile_fh, join(reverse_category_arr," ")  )
# does not work in cygwin
#      if ismatch(r"\r$", lineln) # windows line ending
#        write(rgramfile_fh, "\n\r")
#      else
        write(rgramfile_fh, "\n")

#      end
      n=n+1
    end
  end

  close(rgramfile_fh)
  println("$gramfile has $n rules")
  println("---")
end

# copy each category entry in .voca file (line beginning with '%'% to temp file
# containing only category information, to format required by mkfa:
#  #NS_B
#  #NS_E
#  #VOXFORGE
#  #VOXFORGE_CAT
function make_category_voca(vocafile,termfile,tmpvocafile)
  tmpvocafile_fh=open(tmpvocafile,"w")
  termfile_fh=open(termfile,"w")

  vocafile_arr=open(readlines, vocafile) # automatically closes file handle 
  n1=0
  n2=0
  termid=0
  for lineln=vocafile_arr
    if ismatch(r"\r$", lineln)
      lineend="\r\n" # windows line ending
    else
      lineend="\n" # unix/linux line ending
    end
    line=replace(chomp(lineln), r"#.*", "") # remove line endings & comments

    m=match(r"^%[ \t]*([A-Za-z0-9_]*)", line)
    if m == nothing
      n2=n2+1
    else
      found=m.captures[1] 

      write(tmpvocafile_fh, "\#$found$(lineend)")
      write(termfile_fh, "$termid\t$found$(lineend)")

      termid=termid+1
      n1=n1+1
    end
  end

  close(tmpvocafile_fh)
  close(termfile_fh)
  println("$vocafile has $n1 categories and $n2 words")
  println("generated: $termfile")
  println("---")
end

# convert VoxShell .vox file format (modified version of Julius .voca file):
#  % NS_B
#  <s>
#
#  % NS_E
#  </s>
#
#  % FILLER
#  [] UH
#  [] WELL
#  [] HUM
#
#  % VOXFORGE
#  [COM] VOXFORGE
#  [COM] FIREFOX
#
#  % VOXFORGE_CAT
#  [firefox -remote openurl(http://www.voxforge.org)] HOME
#  [firefox -remote openurl(http://www.voxforge.org/home/read)] READ
#
# to a Julius format .dict file to be 
# used by Julius:
#   0	[<s>] sil
#   1	[</s>] sil
#   2	[] ah
#   2	[] w eh l
#   2	[] hh ah m
#   3	[COM] v aa k s f ao r jh
#   3	[COM] f ay r f aa k s
#   4	[firefox -remote openurl(http://www.voxforge.org)] hh ow m
#   4 [firefox -remote openurl(http://www.voxforge.org/home/read)] r eh d
function vfvoca2dict(vocafile,dic,dictfile)
  dic_hash=Dict{String,String}()
  dictfile_fh=open(dictfile,"w")

  # read in pronunciation dictionary
  function get_pron_dict()
    dic_arr=open(readlines, dic) # automatically closes file handle 
    for lineln=dic_arr
      line=replace(chomp(lineln), r"#.*", "") # remove line endings & comments
      line_arr=split(line,r"[\s\t]+")
      uniq_word=shift!(line_arr)
      return_word=shift!(line_arr)
      phones=join(line_arr," ")
      dic_hash[uniq_word]=phones
    end
    dic_hash["<s>"]="sil"
    dic_hash["</s>"]="sil"
  end 

  function processLine(newid, line)
    # compound words are separated by dashes, but pronunciation is looked up for 
    # each individual word, and these are combined into one pronunciation list
    # Note: no need to check in VoxForgeDict to see if word is already defined,
    # because if it is, then the triphones you need are already defined, and 
    # that's all that matters
    function process_compound_word(command, word)
      compound_word=split(word,r"\-")
      write(dictfile_fh, "$(newid)\t$command ")
      #for word=compound_word
      for i=1:length(compound_word)-1
        word=dic_hash[compound_word[i]]
        #write(dictfile_fh, "$word sp ") # do you really need a sort pause???
        write(dictfile_fh, "$word ")
      end
      i=i+1
      word=dic_hash[compound_word[i]]
      write(dictfile_fh, "$word \n")
    end

    # extract command from line
    command=(match(r"\[.*\]", line)).match
    # remove command within brackets and trailing spaces or tabs; drop empties
    # put into one element array
    word_arr=split(line,r"\[(.*)\][\s\t]*", false)
    words=split(word_arr[1],r"[\s\t]+")

    # for each word on the line, create a dict file entry
    for word=words
      if (ismatch(r"\-", word)) # compound word
        process_compound_word(command, word)
      else
        write(dictfile_fh, "$(newid)\t$command $(dic_hash[word])\n")
      end
    end
  end

  # open .vox file for processing
  function processVoxFile()
    vocafile_arr=open(readlines, vocafile) # automatically closes file handle
    newid=-1
    for lineln=vocafile_arr
      if ismatch(r"\r$", lineln)
        lineend="\r\n" # windows line ending
      else
        lineend="\n" # unix/linux line ending
      end

      line=replace(chomp(lineln), r"#.*", "") # remove line endings & comments
      if ismatch(r"^[\s\t]*$", line) # skip blank lines
        continue
      end

      if ismatch(r"^%", line)
        newid=newid+1
      elseif ismatch(r"\<s\>", line) # get a bounds error if search for <s> or </s>
        write(dictfile_fh, "$(newid)\t[<s>] sil\n")
      elseif ismatch(r"\<\/s\>", line) # get a bounds error if search for <s> or </s>
        write(dictfile_fh, "$(newid)\t[</s>] sil\n")
      else
        processLine(newid, line)
      end
    end
  end

  get_pron_dict()
  processVoxFile()

  close(dictfile_fh)
  println("generated: $dictfile")
end

function main (grammar_prefix, gramfile, vocafile, termfile, dfafile, dictfile, mkfa, dfa_minimize, voxforge_dict)
  workingfolder=mktempdir()
  println("workingfolder: $(workingfolder)")
  rgramfile= "$(workingfolder)/g$(getpid()).grammar"
#  gramfile="$(grammar_prefix).grammar"
#  vocafile=grammar_prefix * ".vox"
#  termfile=grammar_prefix * ".term"
  tmpvocafile="$(workingfolder)/g$(getpid()).vox"
#  dfafile=grammar_prefix * ".dfa"
#  dictfile="$(grammar_prefix).dict"
  headerfile="$(workingfolder)/g$(getpid()).h"

  reverse_grammar(rgramfile,gramfile)


  make_category_voca(vocafile,termfile,tmpvocafile)
  println("dir $(pwd())") # !!!!!!
  # mkfa outputs dfafile.tmp and headerfile.h (not sure what it is used for)
  run(`$mkfa -e1 -fg $rgramfile -fv $tmpvocafile -fo $(dfafile).tmp -fh $headerfile`)
  # dfa_minimize compresses dfafile.tmp (if it can) to .dfa file
  run(`$dfa_minimize $(dfafile).tmp -o $dfafile`)

  vfvoca2dict(vocafile,voxforge_dict,dictfile)

  rm("$(dfafile).tmp")
  rm(rgramfile)
  rm(tmpvocafile)
  rm(headerfile)
end

if length(ARGS) > 0 
  grammar_folder=ARGS[1] 
  grammar_prefix=ARGS[2] 
  mkfa_dir=ARGS[3]
  dfa_minimize_dir=ARGS[4]  
  voxforge_dict=ARGS[5] 

  # grammar prefix must be same for .vox and .grammar files
  gramfile="$(grammar_folder)/$(grammar_prefix).grammar"
  if ! isfile(gramfile)
    error("can't find gramfile file: $(gramfile)")
  end
  vocafile="$(grammar_folder)/$(grammar_prefix).vox"
  if ! isfile(vocafile)
    error("can't find vox file: $(vocafile)")
  end

  mkfa= @windows ? "$(mkfa_dir)/mkfa.exe" : "$(mkfa_dir)/mkfa"
  dfa_minimize= @windows ? "$(dfa_minimize_dir)/dfa_minimize.exe" : "$(dfa_minimize_dir)/dfa_minimize"
  if ! isfile(mkfa)
    error("can't find mkfa executable: $(mkfa)")
  end
  if ! isfile(dfa_minimize)
    error("can't find mkfa executable: $(dfa_minimize)")
  end

  if ! isfile(voxforge_dict)
    error("can't find voxforge_dict file: $(voxforge_dict)")
  end
  if length(ARGS) > 5
    error("mkdfa: too many arguments for call from command line")
  end

  termfile="$(grammar_folder)/$(grammar_prefix).term"
  dfafile="$(grammar_folder)/$(grammar_prefix).dfa"
  dictfile="$(grammar_folder)/$(grammar_prefix).dict"

  main(grammar_prefix, gramfile, vocafile, termfile, dfafile, dictfile, mkfa, dfa_minimize, voxforge_dict)
else
  println("must be called from command line")
  println("usage: juliua compile_grammar.jl grammarPrefixWithPath mkfaFolder voxforge_dict")
end

#!/usr/bin/env ruby
#
# gem install yahoo-weather
# sudo apt-get install festival lame
# gem install festivaltts4r

require 'optparse'
require 'rubygems'
require 'yahoo-weather'
require "festivaltts4r"

options = {}
OptionParser.new do |opts|
  opts.banner = "Usage: example.rb [options]"

  opts.on("-k", "--keywords", "display grammar keywords") do |k|
    options[:keywords] = k
  end
end.parse!

if (options[:keywords]) == true
  puts "RUBY-WEATHER RUBY-TEMPERATURE"
  abort
end

@client = YahooWeather::Client.new
# look up WOEID via http://weather.yahoo.com; enter location by city
# name or zip and WOEID is at end of resulting page url.  herein we use
# the WOEID for London, Ontario, Canada.
response = @client.lookup_by_woeid(4063)

# straight text output
print <<EDOC
#{response.title}
#{response.condition.temp} degrees
#{response.condition.text}
EDOC

"#{response.condition.temp}, degrees. #{response.condition.text}".to_speech

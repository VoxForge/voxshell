if HAVE_DOXYGEN

directory = $(top_srcdir)/docs/

dist_man_MANS = $(directory)/html
$(directory)/html: doxyfile.stamp

doxyfile.stamp:
	$(DOXYGEN) Doxyfile
	echo Timestamp > doxyfile.stamp

CLEANFILES = doxyfile.stamp

all-local: doxyfile.stamp
clean-local:
	rm -rf $(top_srcdir)/docs/html

endif 

# Sin-Yaw Wang <swang24@scu.edu>
CXX=c++
OPT=-g
STD=-std=c++20
CXXFLAGS=$(OPT) $(STD)

%.o:  %.cxx
	$(CXX) -c $(CXXFLAGS) $<

%:  %.cxx
	$(CXX) -o $@ $(CXXFLAGS) $<


ALL= stldemo person
ALLSRCS=$(ALL:=.cxx)

SSRCS= personmain.cxx person.cxx
SOBJS=$(SSRCS:.cxx=.o)
all:    $(ALL)

clean:
	/bin/rm -f $(ALL) $(SOBJS)
	/bin/rm -rf $(ALL:=.dSYM) search.dSYW

person:	$(SOBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

depend: $(ALLSRCS) $(SSRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
stldemo.o: stldemo.cxx
person.o: person.cxx person.h
personmain.o: personmain.cxx person.h
person.o: person.cxx person.h

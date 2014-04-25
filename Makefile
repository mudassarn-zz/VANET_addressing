#
# OMNeT++/OMNEST Makefile for VANET
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/ethernet -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/ieee80211/radio -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/common -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/icmpv6 -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/world/obstacles -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/xmipv6 -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/manetrouting/base -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/contract -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/mobility -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/autorouting/ipv4 -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/ieee80211/mgmt -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/util -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/transport/contract -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/common -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/status -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/radio/propagation -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/ieee80211/radio/errormodel -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/radio -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/util/headerserializers/tcp -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/ipv4 -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/util/headerserializers/ipv4 -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/base -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/util/headerserializers -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/world/radio -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/ieee80211/mac -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/ipv6 -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/transport/sctp -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/util/headerserializers/udp -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/ipv6tunneling -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/battery/models -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/applications/pingapp -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/linklayer/contract -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/util/headerserializers/sctp -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/networklayer/arp -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/transport/tcp_common -I/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/src/transport/udp -L/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet/out/$$\(CONFIGNAME\)/src -linet -DINET_IMPORT -KINET_PROJ=/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet
#

# Name of target to be created (-o option)
TARGET = VANET$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(INET_PROJ)/src/linklayer/ethernet \
    -I$(INET_PROJ)/src/linklayer/ieee80211/radio \
    -I$(INET_PROJ)/src/networklayer/common \
    -I$(INET_PROJ)/src \
    -I$(INET_PROJ)/src/networklayer/icmpv6 \
    -I$(INET_PROJ)/src/world/obstacles \
    -I$(INET_PROJ)/src/networklayer/xmipv6 \
    -I$(INET_PROJ)/src/networklayer/manetrouting/base \
    -I$(INET_PROJ)/src/networklayer/contract \
    -I$(INET_PROJ)/src/mobility \
    -I$(INET_PROJ)/src/networklayer/autorouting/ipv4 \
    -I$(INET_PROJ)/src/linklayer/ieee80211/mgmt \
    -I$(INET_PROJ)/src/util \
    -I$(INET_PROJ)/src/transport/contract \
    -I$(INET_PROJ)/src/linklayer/common \
    -I$(INET_PROJ)/src/status \
    -I$(INET_PROJ)/src/linklayer/radio/propagation \
    -I$(INET_PROJ)/src/linklayer/ieee80211/radio/errormodel \
    -I$(INET_PROJ)/src/linklayer/radio \
    -I$(INET_PROJ)/src/util/headerserializers/tcp \
    -I$(INET_PROJ)/src/networklayer/ipv4 \
    -I$(INET_PROJ)/src/util/headerserializers/ipv4 \
    -I$(INET_PROJ)/src/base \
    -I$(INET_PROJ)/src/util/headerserializers \
    -I$(INET_PROJ)/src/world/radio \
    -I$(INET_PROJ)/src/linklayer/ieee80211/mac \
    -I$(INET_PROJ)/src/networklayer/ipv6 \
    -I$(INET_PROJ)/src/transport/sctp \
    -I$(INET_PROJ)/src/util/headerserializers/udp \
    -I$(INET_PROJ)/src/networklayer/ipv6tunneling \
    -I$(INET_PROJ)/src/battery/models \
    -I$(INET_PROJ)/src/applications/pingapp \
    -I$(INET_PROJ)/src/linklayer/contract \
    -I$(INET_PROJ)/src/util/headerserializers/sctp \
    -I$(INET_PROJ)/src/networklayer/arp \
    -I$(INET_PROJ)/src/transport/tcp_common \
    -I$(INET_PROJ)/src/transport/udp \
    -I. \
    -Iresults

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(INET_PROJ)/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath $(INET_PROJ)/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/MACHack.o $O/RSU.o $O/Vehicle.o $O/VehicleApp.o $O/VAPacket_m.o

# Message files
MSGFILES = \
    VAPacket.msg

# Other makefile variables (-K)
INET_PROJ=/Users/mudassar/courses/sem2/wireless_security/omnetpp-4.4/samples/inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f VANET VANET.exe libVANET.so libVANET.a libVANET.dll libVANET.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f results/*_m.cc results/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc results/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/MACHack.o: MACHack.cc \
	MACHack.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h
$O/RSU.o: RSU.cc \
	RSU.h \
	VAPacket_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h
$O/VAPacket_m.o: VAPacket_m.cc \
	VAPacket_m.h
$O/Vehicle.o: Vehicle.cc \
	VAPacket_m.h \
	Vehicle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h
$O/VehicleApp.o: VehicleApp.cc \
	VAPacket_m.h \
	VehicleApp.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h


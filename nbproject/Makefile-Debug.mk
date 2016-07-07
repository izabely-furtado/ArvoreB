#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Arvore/arvore.o \
	${OBJECTDIR}/Arvore/arvore2.o \
	${OBJECTDIR}/Arvore/arvoreB.o \
	${OBJECTDIR}/Arvore/arvvar.o \
	${OBJECTDIR}/Arvore/main.o \
	${OBJECTDIR}/Arvore/util.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES=

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Arvore/arvore.o: Arvore/arvore.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvore.o Arvore/arvore.c

${OBJECTDIR}/Arvore/arvore2.o: Arvore/arvore2.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvore2.o Arvore/arvore2.c

${OBJECTDIR}/Arvore/arvoreB.o: Arvore/arvoreB.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvoreB.o Arvore/arvoreB.c

${OBJECTDIR}/Arvore/arvvar.o: Arvore/arvvar.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvvar.o Arvore/arvvar.c

${OBJECTDIR}/Arvore/main.o: Arvore/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/main.o Arvore/main.cpp

${OBJECTDIR}/Arvore/util.o: Arvore/util.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/util.o Arvore/util.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${OBJECTDIR}/Arvore/arvore_nomain.o: ${OBJECTDIR}/Arvore/arvore.o Arvore/arvore.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arvore/arvore.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvore_nomain.o Arvore/arvore.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Arvore/arvore.o ${OBJECTDIR}/Arvore/arvore_nomain.o;\
	fi

${OBJECTDIR}/Arvore/arvore2_nomain.o: ${OBJECTDIR}/Arvore/arvore2.o Arvore/arvore2.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arvore/arvore2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvore2_nomain.o Arvore/arvore2.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Arvore/arvore2.o ${OBJECTDIR}/Arvore/arvore2_nomain.o;\
	fi

${OBJECTDIR}/Arvore/arvoreB_nomain.o: ${OBJECTDIR}/Arvore/arvoreB.o Arvore/arvoreB.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arvore/arvoreB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvoreB_nomain.o Arvore/arvoreB.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Arvore/arvoreB.o ${OBJECTDIR}/Arvore/arvoreB_nomain.o;\
	fi

${OBJECTDIR}/Arvore/arvvar_nomain.o: ${OBJECTDIR}/Arvore/arvvar.o Arvore/arvvar.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arvore/arvvar.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/arvvar_nomain.o Arvore/arvvar.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Arvore/arvvar.o ${OBJECTDIR}/Arvore/arvvar_nomain.o;\
	fi

${OBJECTDIR}/Arvore/main_nomain.o: ${OBJECTDIR}/Arvore/main.o Arvore/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arvore/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/main_nomain.o Arvore/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Arvore/main.o ${OBJECTDIR}/Arvore/main_nomain.o;\
	fi

${OBJECTDIR}/Arvore/util_nomain.o: ${OBJECTDIR}/Arvore/util.o Arvore/util.c 
	${MKDIR} -p ${OBJECTDIR}/Arvore
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Arvore/util.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arvore/util_nomain.o Arvore/util.c;\
	else  \
	    ${CP} ${OBJECTDIR}/Arvore/util.o ${OBJECTDIR}/Arvore/util_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

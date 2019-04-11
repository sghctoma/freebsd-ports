# $FreeBSD$

PORTNAME=		ghidra
PORTVERSION=	9.0.2
CATEGORIES=		devel
MASTER_SITES=	SF/yajsw/yajsw/yajsw-stable-12.12/:yajsw \
	SF/catacombae/HFSExplorer/0.21/:hfsexplorer \
	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/android4me/:axml2printer \
	https://github.com/pxb1988/dex2jar/releases/download/2.0/:dex2jar
DISTFILES=		yajsw-stable-12.12.zip:yajsw \
	hfsexplorer-0_21-bin.zip:hfsexplorer \
	AXMLPrinter2.jar:axml2printer \
	dex-tools-2.0.zip:dex2jar
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Software reverse engineering (SRE) suite of tools

LICENSE=		APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS= amd64

EXTRACT_DEPENDS= ${UNZIP_CMD}:archivers/unzip
BUILD_DEPENDS=	gradle>=5.0:devel/gradle \
	bash:shells/bash \
	flex:textproc/flex \
	fop:textproc/fop \
	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl
RUN_DEPENDS=	bash:shells/bash

USES=	bison shebangfix

OPTIONS_RADIO=	JDK
OPTIONS_RADIO_JDK=	JDK11 JDK12
OPTIONS_DEFAULT=	JDK11

JDK11_BUILD_DEPENDS=	${LOCALBASE}/openjdk11/bin/java:java/openjdk11
JDK11_RUN_DEPENDS=		${LOCALBASE}/openjdk11/bin/java:java/openjdk11
JDK12_BUILD_DEPENDS=	${LOCALBASE}/openjdk12/bin/java:java/openjdk12
JDK12_RUN_DEPENDS=		${LOCALBASE}/openjdk12/bin/java:java/openjdk12

SHEBANG_FILES=	Ghidra/RuntimeScripts/Linux/* \
	Ghidra/RuntimeScripts/Linux/support/* \
	Ghidra/RuntimeScripts/Linux/server/*

USE_GITHUB=	yes
GH_ACCOUNT=	NationalSecurityAgency
GH_PROJECT=	ghidra
GH_TAGNAME=	Ghidra_${PORTVERSION}_build
GH_TUPLE=	NationalSecurityAgency:ghidra:Ghidra_${PORTVERSION}_build

GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-home CC=${CC} CXX=${CXX}
GRADLE_RUN=	${SETENV} ${GRADLE_ENV} gradle --no-daemon

post-extract:
	@${MKDIR} ${WRKDIR}/flatrepo
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/AXMLPrinter2.jar ${WRKDIR}/flatrepo
	@${UNZIP_CMD} -j -d ${WRKDIR}/flatrepo ${DISTDIR}/${DIST_SUBDIR}/hfsexplorer-0_21-bin.zip \
		lib/csframework.jar lib/hfsx_dmglib.jar lib/hfsx.jar lib/iharder-base64.jar
	@${UNZIP_CMD} -j -d ${WRKDIR}/flatrepo ${DISTDIR}/${DIST_SUBDIR}/dex-tools-2.0.zip "dex2jar-2.0/lib/dex-*.jar"
	@${MKDIR} ${WRKDIR}/ghidra.bin/Ghidra/Features/GhidraServer/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/yajsw-stable-12.12.zip ${WRKDIR}/ghidra.bin/Ghidra/Features/GhidraServer/

post-patch:
	@${REINPLACE_CMD} -e "s|FLATREPO_PATH_PLACEHOLDER|${WRKDIR}/flatrepo|" ${WRKSRC}/build.gradle
	@${REINPLACE_CMD} -e "s|/usr/share/sgml/docbook/xsl-stylesheets|${LOCALBASE}/share/xsl/docbook/|g" \
		${WRKSRC}/Ghidra/Features/Decompiler/src/main/doc/*.xsl \
		${WRKSRC}/Ghidra/Features/FunctionID/src/main/doc/*.xsl

	# Need to remove .orig and .bak files. They cause build failure because they
	# are not listed in the certification.manifest files.
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} {} \;

post-patch-JDK11-on:
	@${ECHO_CMD} "org.gradle.java.home=${LOCALBASE}/openjdk11" > ${WRKSRC}/gradle.properties

post-patch-JDK12-on:
	@${ECHO_CMD} "org.gradle.java.home=${LOCALBASE}/openjdk12" > ${WRKSRC}/gradle.properties

do-build:
	@${MKDIR} ${WRKDIR}/gradle-home
	cd ${WRKSRC} && ${GRADLE_RUN} yajswDevUnpack
	cd ${WRKSRC} && ${GRADLE_RUN} buildGhidra

do-install:
	@${UNZIP_CMD} -d ${STAGEDIR} ${WRKSRC}/build/dist/*.zip
	@${MV} ${STAGEDIR}/ghidra* ${STAGEDIR}${DATADIR}
	@${RLN} ${STAGEDIR}/${DATADIR}/ghidraRun ${STAGEDIR}${PREFIX}/bin/ghidra
	@${RLN} ${STAGEDIR}/${DATADIR}/server/ghidraSvr ${STAGEDIR}${PREFIX}/bin/ghidra-server
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/GPL/DemanglerGnu/os/freebsd64/demangler_gnu
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/Ghidra/Features/Decompiler/os/freebsd64/decompile
	@${STRIP_CMD} ${STAGEDIR}/${DATADIR}/Ghidra/Features/Decompiler/os/freebsd64/sleigh

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>

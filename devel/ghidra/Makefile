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
	bison:devel/bison \
	flex:textproc/flex \
	fop:textproc/fop \
	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl
RUN_DEPENDS=	bash:shells/bash

USES=	shebangfix

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

USE_GITHUB=		yes

GH_ACCOUNT=		NationalSecurityAgency
GH_PROJECT=		ghidra
GH_TAGNAME=		Ghidra_${PORTVERSION}_build
GH_TUPLE=	NationalSecurityAgency:ghidra:Ghidra_${PORTVERSION}_build

GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-home CC=${CC} CXX=${CXX}
GRADLE_RUN=	${SETENV} ${GRADLE_ENV} gradle --no-daemon

post-extract:
	# Get dependencies for Ghidra
	@${MKDIR} ${WRKDIR}/flatrepo
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/AXMLPrinter2.jar ${WRKDIR}/flatrepo
	@${UNZIP_CMD} -j -d ${WRKDIR}/flatrepo ${DISTDIR}/${DIST_SUBDIR}/hfsexplorer-0_21-bin.zip \
		lib/csframework.jar lib/hfsx_dmglib.jar lib/hfsx.jar lib/iharder-base64.jar
	@${UNZIP_CMD} -j -d ${WRKDIR}/flatrepo ${DISTDIR}/${DIST_SUBDIR}/dex-tools-2.0.zip "dex2jar-2.0/lib/dex-*.jar"

	# Get dependency for Ghidra server
	@${MKDIR} ${WRKDIR}/ghidra.bin/Ghidra/Features/GhidraServer/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/yajsw-stable-12.12.zip ${WRKDIR}/ghidra.bin/Ghidra/Features/GhidraServer/

post-patch:
	# Set flatrepo path
	@${REINPLACE_CMD} -e "s|FLATREPO_PATH_PLACEHOLDER|${WRKDIR}/flatrepo|" ${WRKSRC}/build.gradle

	# Patch include paths in .xsl files
	@${REINPLACE_CMD} -e "s|/usr/share/sgml/docbook/xsl-stylesheets/html/docbook.xsl|${LOCALBASE}/share/xsl/docbook/html/docbook.xsl|g" \
		${WRKSRC}/Ghidra/Features/Decompiler/src/main/doc/main_html.xsl
	@${REINPLACE_CMD} -e "s|/usr/share/sgml/docbook/xsl-stylesheets/html/chunk.xsl|${LOCALBASE}/share/xsl/docbook/html/chunk.xsl|g" \
		${WRKSRC}/Ghidra/Features/Decompiler/src/main/doc/*_html.xsl ${WRKSRC}/Ghidra/Features/FunctionID/src/main/doc/fid_html.xsl
	@${REINPLACE_CMD} -e "s|/usr/share/sgml/docbook/xsl-stylesheets/fo/docbook.xsl|${LOCALBASE}/share/xsl/docbook/fo/docbook.xsl|g" \
		${WRKSRC}/Ghidra/Features/Decompiler/src/main/doc/*_html.xsl ${WRKSRC}/Ghidra/Features/FunctionID/src/main/doc/fid_pdf.xsl

	# Need to remove .orig and .bak files, because they are not in the
	# certification.manifest files, and cause build failure.
	${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} {} \;

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

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>

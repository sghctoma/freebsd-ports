# $FreeBSD$

PORTNAME=	garminplugin
PORTVERSION=	0.3.27
CATEGORIES=	astro

MAINTAINER=	sghctoma@gmail.com
COMMENT=	A browser plugin to support Garmin Devices

LICENSE=	GPLv3

LIB_DEPENDS=	libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgarmintools.so:${PORTSDIR}/astro/garmintools

USE_GITHUB=	yes
GH_ACCOUNT=	adiesner
GH_PROJECT=	GarminPlugin
GH_TAGNAME=	V0.3.27
GH_COMMIT=	c610187

#WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/src
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/src

PLIST_FILES=	${WEBPLUGIN_DIR}/npGarminPlugin.so
PLIST_DIRSTRY=	${WEBPLUGIN_DIR}

USES=		dos2unix
USES+=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= LIBUSB_LIBS=-lusb \
		LIBUSB_CFLAGS=-I${LOCALBASE}/include \
		ZLIB_LIBS=-lz \
		ZLIB_CFLAGS=-I${LOCALBASE}/include \
		--with-tinyxml-incdir=${LOCALBASE}/include \
		--with-tinyxml-libdir=${LOCALBASE}/lib \
		--with-libgcrypt-prefix=${LOCALBASE} \
		--with-garmintools-incdir=${LOCALBASE}/include \
		--with-garmintools-libdir=${LOCALBASE}/lib

USES+=		webplugin:native
WEBPLUGIN_FILES=npGarminPlugin.so

do-install:
		${MKDIR} ${WEBPLUGIN_DIR}
		${INSTALL_DATA} ${WEBPLUGIN_FILES:S,^,${WRKSRC}/,} \
			${WEBPLUGIN_DIR}

post-install:
		${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
		${INSTALL_DATA} ${WEBPLUGIN_FILES:S,^,${WRKSRC}/,} \
			${STAGEDIR}${WEBPLUGIN_DIR}

.include <bsd.port.mk>

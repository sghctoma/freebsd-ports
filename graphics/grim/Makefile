# $FreeBSD$

PORTNAME=	grim
PORTVERSION=	0.0.0
CATEGORIES=	graphics

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Grab images from a Wayland compositor

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
	libwayland-cursor.so:graphics/wayland \
	libcairo.so:graphics/cairo \
	libjpeg.so:graphics/jpeg-turbo

USES=	meson ninja

USE_GITHUB= yes
GH_ACCOUNT=	emersion
GH_PROJECT=	grim
GH_TAGNAME=	97202f2

PLIST_FILES=	bin/grim \
				man/man1/grim.1.gz

.include <bsd.port.mk>

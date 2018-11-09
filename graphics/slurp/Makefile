# $FreeBSD$

PORTNAME=	slurp
PORTVERSION=	0.0.0
CATEGORIES=	graphics

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Select a region in a Wayland compositor

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
	libwayland-cursor.so:graphics/wayland \
	libcairo.so:graphics/cairo

USES=	meson ninja pkgconfig

USE_GITHUB= yes
GH_ACCOUNT=	emersion
GH_PROJECT=	slurp
GH_TAGNAME=	d907d30

PLIST_FILES=	bin/slurp \
				man/man1/slurp.1.gz

.include <bsd.port.mk>

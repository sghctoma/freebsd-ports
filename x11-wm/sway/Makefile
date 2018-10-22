# $FreeBSD$

PORTNAME=	sway
DISTVERSION=	1.0-beta.1
CATEGORIES=	x11-wm wayland

MAINTAINER=	sghctoma@gmail.com
COMMENT=	i3-compatible Wayland compositor

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libjson-c.so:devel/json-c \
	libpcre.so:devel/pcre \
	libwlroots.so:x11-toolkits/wlroots \
	libpango-1.0.so:x11-toolkits/pango

USES=	meson ninja
USE_XORG=	pixman x11 xcb
USE_GL=     egl gbm glesv2
USE_HARDENING=	pie relro
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	swaywm
GH_PROJECT=	sway

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SUID
OPTIONS_DEFAULT=	SUID
SUID_DESC=	Install sway binary with setuid bit set

.include <bsd.port.mk>

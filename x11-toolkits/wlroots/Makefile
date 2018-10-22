# $FreeBSD$

PORTNAME=	wlroots
PORTVERSION=	0.1
CATEGORIES=	x11-toolkits wayland

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Pluggable, composable modules for building a Wayland compositor

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
	libwayland-egl.so:graphics/wayland \
	libinput.so:x11/libinput \
	libxkbcommon.so:x11/libxkbcommon \
	libudev.so:devel/libudev-devd \
	libxcb-image.so:x11/xcb-util-image \
	libxcb-icccm.so:x11/xcb-util-wm

USES=	meson ninja

USE_GITHUB=	yes
GH_ACCOUNT=	swaywm
GH_PROJECT=	wlroots

OPTIONS_DEFINE=	XWAYLAND X11_BACKEND ROOTSTON EXAMPLES
OPTIONS_DEFAULT=	XWAYLAND X11_BACKEND ROOTSTON EXAMPLES

#XWAYLAND_MESON_TRUE=	xwayland
#X11_BACKEND_MESON_TRUE=	x11_backend
ROOTSTON_MESON_TRUE=	rootston
EXAMPLES_MESON_TRUE=	examples

#XWAYLAND_DESC=	Enable support X11 applications
#X11_BACKEND_DESC=	Enable X11 backend
ROOTSTON_DESC=	Build the rootston example compositor
EXAMPLES_DESC=	Build example applications

MESON_ARGS+= \
	-Dlibcap=disabled \
	-Dlogind=disabled \
	-Dxcb-errors=disabled

USE_XORG=	pixman x11 xcb
USE_GL=     egl gbm glesv2
USE_HARDENING=	pie relro
USE_LDCONFIG=	yes

.include <bsd.port.mk>

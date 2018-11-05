# $FreeBSD$

PORTNAME=	wlroots
PORTVERSION=	0.1.0
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
GH_ACCOUNT=	sghctoma
GH_PROJECT=	wlroots
GH_TAGNAME=	bef882a1

OPTIONS_DEFINE=	XWAYLAND X11_BACKEND
OPTIONS_DEFAULT=	XWAYLAND X11_BACKEND

XWAYLAND_MESON_ON=	-Dxwayland=enabled
XWAYLAND_MESON_OFF=	-Dxwayland=disabled
X11_BACKEND_MESON_ON=	-Dx11_backend=enabled
X11_BACKEND_MESON_OFF=	-Dx11_backend=disabled

XWAYLAND_DESC=	Enable support X11 applications
X11_BACKEND_DESC=	Enable X11 backend

MESON_ARGS+= \
	-Dlibcap=disabled \
	-Dlogind=disabled \
	-Dxcb-errors=disabled \
	-Drootston=false \
	-Dexamples=false

USE_XORG=	pixman x11 xcb
USE_GL=     egl gbm glesv2
USE_HARDENING=	pie relro
USE_LDCONFIG=	yes

.include <bsd.port.mk>

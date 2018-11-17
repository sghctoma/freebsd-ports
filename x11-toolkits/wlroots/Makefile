# $FreeBSD$

PORTNAME=	wlroots
PORTVERSION=	0.1.20181113
CATEGORIES=	x11-toolkits wayland

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Pluggable, composable modules for building a Wayland compositor

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
	scdoc:textproc/scdoc
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
	libwayland-egl.so:graphics/wayland \
	libinput.so:x11/libinput \
	libxkbcommon.so:x11/libxkbcommon \
	libudev.so:devel/libudev-devd

USES=			meson ninja pkgconfig

USE_GITHUB=		yes
GH_ACCOUNT=		sghctoma
GH_PROJECT=		wlroots
GH_TAGNAME=	48a73bbb

USE_XORG=		pixman
USE_GL=			egl gbm glesv2
USE_LDCONFIG=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=		XWAYLAND X11_BACKEND XCB_ICCCM ROOTSTON EXAMPLES
OPTIONS_DEFAULT=	XWAYLAND X11_BACKEND XCB_ICCCM

XCB_ICCCM_IMPLIES=	XWAYLAND

XWAYLAND_DESC=		Enable support X11 applications
X11_BACKEND_DESC=	Enable X11 backend
XCB_ICCCM_DESC=		Use xcb-icccm util library
ROOTSTON_DESC=		Install the rootston example compositor

XWAYLAND_LIB_DEPENDS=		libxcb.so:x11/libxcb
X11_BACKEND_LIB_DEPENDS=	libX11.so:x11/libX11 libxcb.so:x11/libxcb
XCB_ICCCM_LIB_DEPENDS=		libxcb-icccm.so:x11/xcb-util-wm

XWAYLAND_MESON_ON=		-Dxwayland=enabled
XWAYLAND_MESON_OFF=		-Dxwayland=disabled
X11_BACKEND_MESON_ON=	-Dx11-backend=enabled
X11_BACKEND_MESON_OFF=	-Dx11-backend=disabled
XCB_ICCCM_MESON_ON=		-Dxcb-icccm=enabled
XCB_ICCCM_MESON_OFF=	-Dxcb-icccm=disabled
ROOTSTON_MESON_TRUE=	rootston

MESON_ARGS+= \
	-Dlibcap=disabled \
	-Dlogind=disabled \
	-Dxcb-errors=disabled \
	-Dexamples=false

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

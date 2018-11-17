# $FreeBSD$

PORTNAME=	sway
PORTVERSION=	1.0.20181115
CATEGORIES=	x11-wm wayland

MAINTAINER=	sghctoma@gmail.com
COMMENT=	i3-compatible Wayland compositor

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
	${LOCALBASE}/include/linux/input-event-codes.h:devel/evdev-proto \
	git:devel/git \
	scdoc:textproc/scdoc
LIB_DEPENDS=	libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2 \
	libjson-c.so:devel/json-c \
	libpcre.so:devel/pcre \
	libwlroots.so:x11-toolkits/wlroots \
	libpango-1.0.so:x11-toolkits/pango

USES=	meson ninja pkgconfig
USE_XORG=	pixman
USE_GL=     egl gbm glesv2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sghctoma
GH_PROJECT=	sway
GH_TAGNAME= a2bd421c

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SUID WALLPAPER ZSH_COMPLETIONS BASH_COMPLETIONS \
				FISH_COMPLETIONS XWAYLAND
OPTIONS_DEFAULT=	SUID WALLPAPER XWAYLAND

WALLPAPER_MESON_TRUE=	default-wallpaper
ZSH_COMPLETIONS_MESON_TRUE=	zsh-completions
BASH_COMPLETIONS_MESON_TRUE=	bash-completions
FISH_COMPLETIONS_MESON_TRUE=	fish-completions
XWAYLAND_MESON_TRUE=	enable-xwayland

SUID_DESC=	Install sway and swaylock binaries with setuid bit set
WALLPAPER_DESC=	Install the default wallpaper
ZSH_COMPLETIONS_DESC=	Install zsh shell completions
BASH_COMPLETIONS_DESC=	Install bash shell completions
FISH_COMPLETIONS_DESC=	Install fish shell completions
XWAYLAND_DESC=	Enable support for X11 applications

XWAYLAND_LIB_DEPENDS=		libxcb.so:x11/libxcb

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	pothos
PORTVERSION=	0.3.3
#DISTVERSIONPREFIX=	pothos-
CATEGORIES=	comms

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Framework for creating topologies of interconnected processing \
			blocks

LICENSE=	BSL

LIB_DEPENDS=	libPocoJSON.so:devel/poco-devel \
	libPocoUtil.so:devel/poco-devel \
	libPocoXML.so:devel/poco-devel \
	libPocoNet.so:devel/poco-devel \
	libqwt6.so:x11-toolkits/qwt6-qt5 \
	libmuparserx.so:math/muparserx \
	libportaudio.so:audio/portaudio \
	libSoapySDR.so:comms/soapysdr

USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
GH_TAGNAME=	7ca5f18
GH_TUPLE=	pothosware:pothos-audio:be1bb2d:audio \
	pothosware:pothos-blocks:2ab6519:blocks \
	pothosware:pothos-comms:d99af20:comms \
	pothosware:pothos-gui:50a2675:gui \
	pothosware:pothos-plotters:7d31eb3:plotters \
	pothosware:pothos-python:1845189:python \
	pothosware:pothos-sdr:61620e9:sdr \
	pothosware:pothos-serialization:c59130f:serialization \
	pothosware:pothos-widgets:b27842a:widgets \

post-extract:
	@${RM} -rf ${WRKSRC}/audio
	@${RM} -rf ${WRKSRC}/blocks
	@${RM} -rf ${WRKSRC}/comms
	@${RM} -rf ${WRKSRC}/gui
	@${RM} -rf ${WRKSRC}/plotters
	@${RM} -rf ${WRKSRC}/python
	@${RM} -rf ${WRKSRC}/sdr
	@${RM} -rf ${WRKSRC}/serialization
	@${RM} -rf ${WRKSRC}/widgets
	@${MV} ${WRKSRC_audio} ${WRKSRC}/audio
	@${MV} ${WRKSRC_blocks} ${WRKSRC}/blocks
	@${MV} ${WRKSRC_comms} ${WRKSRC}/comms
	@${MV} ${WRKSRC_gui} ${WRKSRC}/gui
	@${MV} ${WRKSRC_plotters} ${WRKSRC}/plotters
	@${MV} ${WRKSRC_python} ${WRKSRC}/python
	@${MV} ${WRKSRC_sdr} ${WRKSRC}/sdr
	@${MV} ${WRKSRC_serialization} ${WRKSRC}/serialization
	@${MV} ${WRKSRC_widgets} ${WRKSRC}/widgets

USES=	compiler:c++11-lib cmake
CXXFLAGS+=	-stdlib=libc++ \
	-std=c++11 \
	-Wno-c++11-extensions \
	-Wno-inconsistent-missing-override
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DQWT_INCLUDE_DIR=${LOCALBASE}/include/qwt6 \
	-DQWT_LIBRARY=${LOCALBASE}/lib/libqwt6.so \
	-DCMAKE_BUILD_TYPE=Debug

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	pothos
PORTVERSION=	0.4.2
#DISTVERSIONPREFIX=	pothos-
CATEGORIES=	comms

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Framework for creating topologies of interconnected processing \
			blocks

LICENSE=	BSL

LIB_DEPENDS=	libPocoJSON.so:devel/poco \
	libPocoUtil.so:devel/poco \
	libPocoXML.so:devel/poco \
	libPocoNet.so:devel/poco \
	libqwt6.so:x11-toolkits/qwt6-qt5 \
	libmuparserx.so:math/muparserx \
	libportaudio.so:audio/portaudio \
	libSoapySDR.so:comms/soapysdr

USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
GH_TAGNAME=	932b6da
GH_TUPLE=	pothosware:pothos-audio:937a56e:audio \
	pothosware:pothos-blocks:979790a:blocks \
	pothosware:pothos-comms:4699d8f:comms \
	pothosware:pothos-gui:ccda93b:gui \
	pothosware:pothos-plotters:0e50914:plotters \
	pothosware:pothos-python:86ead8b:python \
	pothosware:pothos-sdr:f8dab51:sdr \
	pothosware:pothos-serialization:c59130f:serialization \
	pothosware:pothos-widgets:4a0a52d:widgets \

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

sghctoma's FreeBSD ports playground
===================================

Some ports for FreeBSD that are mostly usable for my use cases but not quite
ready to PR them.

astro/garmintools
-----------------

This port rovides users with the ability to communicate with various Garmin
sport watches and bike computers.

WWW: http://garmintools.googlecode.com

astro/garminplugin
------------------

This browser plugin has the same methods and properties as the official
Garmin Communicator Plugin (http://www8.garmin.com/products/communicator/).
It can be used to transfer GPX files (Geocache Descriptions) to your garmin
device using the official Garmin Javascript API. Its functionality depends on
the device you use.
- Edge305/Forerunner305: ReadFitnessData, ReadGpsData, No write support
- Edge705/Oregon/Dakota: ReadFitnessData, ReadGpsData, Write Gpx files
- Edge800: ReadFitnessData, Write Gpx/Tcx Files
- Other devices: Executes external command to write Gpx to device

WWW: http://www.andreas-diesner.de/garminplugin

audio/spuce
-----------

A rewrite of the digital filter components of SPUC with more testing, better
code design and c++11 features.

 - Uses std::complex instead of custom complex class
 - Will focus of floating point instead of fixed-point modules
 - Includes Chebyshev2 filter
 - Bug fixes for odd order IIR filters
 - Adding support for Bandpass and Bandstop designs for both IIR and FIR filter

Most of spuc was written many years ago before C++ compilers had good template
support and was primarily written for fixed-point hardware design and
simulation.

WWW: https://github.com/audiofilter/spuce


# Base image maintained at https://github.com/olantwin/ship-base and available
# on Docker Hub: https://hub.docker.com/r/olantwin/ship-base/
#
# Prebuilt images available on Docker Hub at:
# https://hub.docker.com/r/olantwin/fairship/
FROM olantwin/ship-base:20181116

# Copy FairShip scripts
#COPY . /FairShip

#my repo
RUN git clone -b master https://github.com/AnnaErsh/FairShip.git

# Build FairShip
RUN aliBuild -c shipdist/ --defaults fairship build FairShip --no-local ROOT && aliBuild clean 

RUN mkdir /sw/slc7_x86-64/FairRoot/latest/include/source && cp /sw/slc7_x86-64/FairRoot/latest/include/*.h /sw/slc7_x86-64/FairRoot/latest/include/source && mkdir /sw/slc7_x86-64/FairRoot/latest/include/steer && cp /sw/slc7_x86-64/FairRoot/latest/include/*.h /sw/slc7_x86-64/FairRoot/latest/include/steer && mkdir /sw/slc7_x86-64/FairRoot/latest/include/sim && cp /sw/slc7_x86-64/FairRoot/latest/include/*.h /sw/slc7_x86-64/FairRoot/latest/include/sim && mkdir /sw/slc7_x86-64/FairRoot/latest/include/field && cp /sw/slc7_x86-64/FairRoot/latest/include/*.h /sw/slc7_x86-64/FairRoot/latest/include/field && mkdir /sw/slc7_x86-64/FairRoot/latest/include/event && cp /sw/slc7_x86-64/FairRoot/latest/include/*.h /sw/slc7_x86-64/FairRoot/latest/include/event

# Setup environment. Setup the command that will be invoked when your docker
# image is run. Note that this requires running with `docker run -t` so that
# `alienv` detects an interactive terminal.
ENTRYPOINT alienv enter --shellrc FairShip/latest

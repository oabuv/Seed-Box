FROM ubuntu:20.04


RUN apt-get install libstdc++6
RUN apt-get update && apt-get upgrade -y
RUN apt-get -y install git gcc make g++
RUN mkdir /opt/src
WORKDIR /opt/src
RUN git clone https://github.com/google/googletest.git

ENV GTEST_DIR=/opt/src/googletest/googletest/
WORKDIR $GTEST_DIR/src
COPY . .

RUN make test
RUN cp ggtest.exe /
CMD ["./ggtest.exe"]
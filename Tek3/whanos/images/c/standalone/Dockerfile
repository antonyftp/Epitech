FROM debian:11

RUN apt-get update -y && \
    apt-get install build-essential -y && \
    apt-get install -y gcc

COPY . .
RUN make
CMD ["./compiled-app"]
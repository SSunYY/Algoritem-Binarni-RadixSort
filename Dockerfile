FROM ubuntu:latest

RUN apt-get update && apt-get install -y g++

WORKDIR /app
COPY . .

RUN g++ -o radix_sort BinarniRadixSort.cpp

ENTRYPOINT ["./radix_sort"]

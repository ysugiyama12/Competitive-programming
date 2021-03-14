cd "/Users/ysugiyama/Documents/1_compro/marathon/ahc001/" && \
c++ -std=c++17 main.cpp && ./a.out < $1 > out/output.txt

cargo run --release --bin vis $1 out/output.txt
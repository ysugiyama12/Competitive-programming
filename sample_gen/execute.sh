cd "/Users/ysugiyama/Documents/compro/sample_gen/" && c++ -std=c++17 generate.cpp && ./a.out > sample.in
cd "/Users/ysugiyama/Documents/compro/sample_gen/" && c++ -std=c++17 code1.cpp && ./a.out < sample.in > sample1.out
cd "/Users/ysugiyama/Documents/compro/sample_gen/" && c++ -std=c++17 code2.cpp && ./a.out < sample.in > sample2.out
colordiff -u sample1.out sample2.out

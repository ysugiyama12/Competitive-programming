package main

import (
	"fmt"
	"strconv"
)

func main() {
	var S string
	fmt.Scan(&S)
	N := len(S)
	var ans string
	pos := -1
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			num := i - pos
			ans += string(S[i]) + strconv.Itoa(num)
			pos = i
		}
	}
	num := N - 1 - pos
	ans += string(S[N-1]) + strconv.Itoa(num)
	fmt.Println(ans)

}

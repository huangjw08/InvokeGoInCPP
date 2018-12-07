package main

import "C"
import "fmt"

//export WriteData
func WriteData(data []string) int{
	fmt.Println("WriteData",data,len(data))
	return 0
}

func main() {}
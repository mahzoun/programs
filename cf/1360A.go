package main

import (
  "fmt"
)

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
  var t int
  fmt.Scan(&t)
  for i := 0 ; i < t; i++ {
    var a, b int
    fmt.Scan(&a, &b)
    x := min(a, b)
    y := max(a, b)
    if x * 2 < y {
      fmt.Println(y * y)
    } else {
      fmt.Println(4 * x * x)
    }
  }
}

package main

import (
  "fmt"
  "time"
)

func contar(num_runtine int)  {
    fmt.Printf("Soy la gorutine %d\n",num_runtine)
    time.Sleep(time.Second*2);
    fmt.Printf("Ya termino la gorutine %d\n",num_runtine)
}

func main() {
  var input string

  go contar(2);
  go contar(3);

  fmt.Scanln(&input)
}

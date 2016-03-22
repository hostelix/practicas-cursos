package main
import "fmt"

//Funciones para slice
/*
append() //Añade
copy() //copia
make() //Retorna un nuevo slice de tipos especificado
cap() //Retorna la capacidad del slice
*/

func main(){
	//nombres := make([]string,0,8)
	//edades := make([]int,0,8)

	nombres := []string{"saray","juan","israel", "debora", "salomon", "ana", "rut", "rafael"}
	edades := []int{25,23,21,18,16,14,10,8}
	hermanos := make(map[string]int)

	//tamano := len(nombres)

	fmt.Printf("Nombres: %v \n",nombres)
	fmt.Printf("Edades: %v\n",edades)


	for index, value := range nombres {
		fmt.Printf("%d -> %s\n",index, value)
		hermanos[value] = edades[index]
	}

	fmt.Println(hermanos)

}

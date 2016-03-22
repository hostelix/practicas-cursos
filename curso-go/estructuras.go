package main

import (
  io "fmt"
)

type Fecha struct {
  dia, mes, ano int
}

func (this *Fecha) set_fecha() {
  io.Printf("Introduce el dia >"); io.Scanf("%d",&this.dia)
  io.Printf("Introduce el mes >"); io.Scanf("%d",&this.mes)
  io.Printf("Introduce el año >"); io.Scanf("%d",&this.ano)
}

type Persona struct  {
  nombre string
  apellido string
  cedula string
  fecha_nacimiento Fecha
}

func (this *Persona) registrar_datos()  {
  io.Printf("Introduce el nombre >"); io.Scanf("%s",&this.nombre)
  io.Printf("Introduce el apellido >"); io.Scanf("%s",&this.apellido)
  io.Printf("Introduce el cedula >"); io.Scanf("%s",&this.cedula)
  this.fecha_nacimiento.set_fecha();
}

func main() {
    hermanos := make([]Persona,2)


    for i := range hermanos{
      hermanos[i].registrar_datos()
    }

    var per Persona;

    per.nombre = "israel"
    per.apellido = "lugo"
    per.cedula = "24352838"

    //per.registrar_datos()

    io.Println(per)
    io.Println(hermanos)

}

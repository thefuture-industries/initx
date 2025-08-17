package main

import (
	"fmt"

	"github.com/joho/godotenv"
)

type httpServer struct {}

func main() {
	if err := godotenv.Load(); err != nil {
		panic(err)
	}

	// connection db
	fmt.Printf("[INFO] Successfully connected to database\n")

	// initial redis

	// initial rabbitmq
	// ----------------
	fmt.Printf("[INFO] Successfully connected to RabbitMQ\n")
	// ----------------
	// initial rabbitmq

	server := &httpServer{}

	// start http server
	if err := server.httpStart(); err != nil {
		log.Error(err.Error())
	}
}
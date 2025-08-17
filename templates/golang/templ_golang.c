#include "templ_golang.h"
#include "templates.h"
#include "fs.h"

#include <string.h>
#include <stdio.h>

static int templ_golang_server(const base_template_struct *s)
{
    char path[256];

    create_dir(s->directory);

    snprintf(path, sizeof(path), "%s/cmd", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/cmd/server", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/config", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/handler", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/infra", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/middleware", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/pkg", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/tests", s->directory);
    create_dir(path);

    snprintf(path, sizeof(path), "%s/util", s->directory);
    create_dir(path);

    // go.mod
    snprintf(path, sizeof(path), "%s/go.mod", s->directory);
    char go_mod[512];
    snprintf(go_mod, sizeof(go_mod), "module %s\n\ngo 1.23.0\n", s->project_name);
    write_file(path, go_mod);

    // Makefile
    snprintf(path, sizeof(path), "%s/Makefile", s->directory);
    char makefile[1024];
    snprintf(makefile, sizeof(makefile), "DB_URL ?= database\nMIGRATIONS_DIR ?= cmd/migrate/migrations\n\nGOOSE ?= goose\n\n.PHONY: fmt lint check build-clean build test migrate-create migrate-up migrate-down\n\nfmt:\n\tgofmt -w .\n\tgoimports -w .\n\nlint:\n\tgolangci-lint run\n\ncheck: fmt lint test\n\t@echo \"==> All checks passed!\"\n\nbuild:\n\t@echo \"==> Running build...\"\n\t@go build -ldflags=\"-s -w\" -o bin/server_bin ./cmd/server\n\ntest:\n\t@go test -v ./...\n\nrun: build\n\t@./bin/server_bin\n\nrun-to-test:\n\t@cmd /c \"$(CURDIR)/$(BATCH_FILE_TEST)\"\n\n## make create NAME=create_users_table\nmigrate-create:\n\t@echo \"==> Creating new migration: $(NAME)\"\n\t$(GOOSE) -dir $(MIGRATIONS_DIR) create $(NAME) sql\n\nmigrate-up:\n\t@echo \"==> Running up migrations\"\n\t$(GOOSE) -dir $(MIGRATIONS_DIR) postgres \"$(DB_URL)\" up\n\nmigrate-down:\n\t@echo \"==> Running down migrations...\"\n\t$(GOOSE) -dir $(MIGRATIONS_DIR) postgres \"$(DB_URL)\" down\n\ndatabase-drop:\n\t@echo \"==> Dropping all tables in database...\"\n\t@psql \"$(DB_URL)\" -c \"DROP SCHEMA public CASCADE; CREATE SCHEMA public;\"\n");
    write_file(path, makefile);

    // main.go
    snprintf(path, sizeof(path), "%s/cmd/server/main.go", s->directory);
    char maingo[2048];
    snprintf(maingo, sizeof(maingo), "package main\n\nimport (\n\t\"fmt\"\n\n\t\"github.com/joho/godotenv\"\n)\n\ntype httpServer struct {}\n\nfunc main() {\n\tif err := godotenv.Load(); err != nil {\n\t\tpanic(err)\n\t}\n\n\t// connection db\n\tfmt.Printf(\"[INFO] Successfully connected to database\\n\")\n\n\t// initial redis\n\n\t// initial rabbitmq\n\t// ----------------\n\tfmt.Printf(\"[INFO] Successfully connected to RabbitMQ\\n\")\n\t// ----------------\n\t// initial rabbitmq\n\n\tserver := &httpServer{}\n\n\t// start http server\n\tif err := server.httpStart(); err != nil {\n\t\tfmt.Printf(\"[ERROR] %s\", err.Error())\n\t}\n}\n");
    write_file(path, maingo);

    // routes.go
    snprintf(path, sizeof(path), "%s/cmd/server/routes.go", s->directory);
    char routesgo[2048];
    snprintf(routesgo, sizeof(routesgo), "package main\n\n//Routes defines and returns all the HTTP routes and their corresponding handlers.\n//This function sets up the routing for the application, mapping paths to handler functions.\nfunc (s *httpServer) routes() http.Handler {}");
    write_file(path, routesgo);

    // server.go
    snprintf(path, sizeof(path), "%s/cmd/server/server.go", s->directory);
    char servergo[2048];
    snprintf(servergo, sizeof(servergo), "package main\n\n//httpStart starts an HTTP server on the specified address.\n//It sets up routes and handlers and listens for incoming HTTP requests.\n//Returns an error if the server fails to start.\nfunc (s *httpServer) httpStart() error {}");
    write_file(path, servergo);
}

int templ_golang(const base_template_struct *s)
{
    if (!strcmp("server", s->scope))
    {
        templ_golang_server(s);
    }
    else
    {
        fprintf(stderr, "error: unsupported scope: '%s'\n", s->scope);
        return 1;
    }

    return 0;
}
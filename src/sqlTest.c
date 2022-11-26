//#include <stdio.h>
//#include <mysql/mysql.h>
//
//
////gcc -Wall teste.c -o teste `mysql_config --cflags --libs`
//
//int createmydb(void);
//
//char server[16] = "localhost";
//char username[16] = "root";
//char password[16] = "52468592kK@#";
//
//int createmydb(void) {
//
//    MYSQL *conn = mysql_init(NULL);
//    if (conn == NULL) {
//        printf("MySQL initialization failed");
//        return(1);
//    }
//
//    if (mysql_real_connect(conn, server, username, password, NULL, 0, NULL, 0) == NULL) {
//        printf("Unable to connect with MySQL server\n");
//        mysql_close(conn);
//        return(1);
//    }
//
//    if (mysql_query(conn, "CREATE TABLE sheet")) {
//        printf("Unable to create database\n");
//        mysql_close(conn);
//        return 1;
//    }
//
//    mysql_close(conn);
//
//    printf("\nDatabase created successfully\n");
//    return(0);
//}
//
//int createtable(){
//    MYSQL *conn = mysql_init(NULL);
//    if (conn == NULL) {
//        printf("MySQL initialization failed");
//        return(1);
//    }
//
//    if (mysql_real_connect(conn, server, username, password, NULL, 0, NULL, 0) == NULL) {
//        printf("Unable to connect with MySQL server\n");
//        mysql_close(conn);
//        return(1);
//    }
//
//    if (mysql_query(conn, "CREATE TABLE sheet("
//                          "id int unsigned auto-increment not null"
//                          ");")) {
//        printf("Unable to create TABLE\n");
//        mysql_close(conn);
//        return 1;
//    }
//
//    mysql_close(conn);
//
//    printf("\nDatabase created successfully\n");
//    return(0);
//}
#include "db_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <model/moviedto.h>
#include <iostream>
#include <sstream>

db_manager::db_manager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName(path);

       if (!m_db.open())
       {
           qDebug() << "Error: connection with database fail";
       }
       else
       {
           qDebug() << "Database: connection ok";
       }
}

db_manager::~db_manager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool db_manager::isOpen() const
{
    return m_db.isOpen();
}

bool db_manager::createTable()
{
    bool success = false;

    QSqlQuery query;
    QSqlQuery query2;
    QSqlQuery query3;

    QSqlQuery query4;
    QSqlQuery query5;
    QSqlQuery query6;
    QSqlQuery query7;
    QSqlQuery query8;

    query.prepare("CREATE TABLE  USERS (userId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,email VARCHAR(64) NOT NULL,username VARCHAR(64) UNIQUE NOT NULL,password VARCHAR(64) NOT NULL);");
    query2.prepare("CREATE TABLE  ROOMS (roomId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name VARCHAR(64) UNIQUE NOT NULL,places VARCHAR NOT NULL);");
    query3.prepare("CREATE TABLE  MOVIES (movieId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name VARCHAR(64) NOT NULL,date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,roomId INTEGER,FOREIGN KEY(roomId) REFERENCES ROOMS(roomId));");

    query4.prepare("INSERT INTO USERS (`email`, `username`, `password`) VALUES (\"kowal@gmail.com\", \"kowal\", \"kowal\"), (\"dziok@gmail.com\", \"dziok\", \"dziok\"), (\"admin@gmail.com\", \"admin\", \"admin\");");

    query5.prepare("INSERT INTO ROOMS ('name', 'places') VALUES (\"Movie theater\", \"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Room 3D\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Room 4D\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\");");
    query6.prepare("INSERT INTO ROOMS ('name', 'places') VALUES (\"A Room with a View\", \"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Panic Room\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Deep efect room\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Green Room\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\");");
    query7.prepare("INSERT INTO ROOMS ('name', 'places') VALUES (\"Red Room\", \"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Standing Room Only\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Room in Rome\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\"), (\"Control Room\",\"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\");");

    query8.prepare("INSERT INTO MOVIES (`name`, `roomId`) VALUES (\"MULAN\" , 1), (\"FAMILY ROMANCE, LLC\" , 2), (\"BLACK BOX\", 3), (\"THE WRETCHED\", 4), (\"THE LODGE\", 5), (\"TO ALL THE BOYS: P.S. I STILL LOVE YOU\", 6), (\"THE OTHER LAMB\", 7), (\"THE GENTLEMEN\", 8), (\"12 HOUR SHIFT\", 9), (\"THE RENTAL\", 10), (\"SUMMERLAND\", 11);");




    if (!query.exec() )
    {
        qDebug() << "Couldn't create the query, one might already exist.";
        success = false;
    }
    if ( !query2.exec())
    {
        qDebug() << "Couldn't create the query2, one might already exist.";
        success = false;
    }
    if (!query3.exec())
    {
        qDebug() << "Couldn't create the query3, one might already exist.";
        success = false;
    }
//    if(!query4.exec()){
//        qDebug() << "Injection query4 error." << query4.lastError();
//    }
//    if(!query5.exec()){
//        qDebug() << "Injection query5 error." << query5.lastError();
//    }
//    if(!query6.exec()){
//        qDebug() << "Injection query6 error." << query6.lastError();
//    }
//    if(!query7.exec()){
//        qDebug() << "Injection query7 error." << query7.lastError();
//    }
//    if(!query8.exec()){
//        qDebug() << "Injection query8 error." << query8.lastError();
//    }


    return success;
}

bool db_manager::login(const QString& name, const QString& pass){
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM USERS WHERE username = (:username) AND password = (:password)");
    checkQuery.bindValue(":username", name);
    checkQuery.bindValue(":password", pass);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person login failed: " << checkQuery.lastError();
    }

    return exists;
}

QList<MovieDTO> db_manager::getMovies()
{
    QList<MovieDTO> movies;
    QSqlQuery query("SELECT name, COUNT(roomId) as cou from MOVIES group by name");
    int nameId= query.record().indexOf("name");
    int countId = query.record().indexOf("cou");

    while (query.next())
    {
        MovieDTO movie;
        movie.setName(query.value(nameId).toString());
        movie.setSession(query.value(countId).toInt());
        movies.append(movie);
    }
    return movies;
}

bool db_manager::addMovie(const QString &name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO MOVIES (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add movie failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add movie failed: name cannot be empty";
    }

    return success;
}

bool db_manager::editMovie(const QString &oldName, const QString &newName)
{
    bool success = false;
    if(!newName.isEmpty() && !oldName.isEmpty()){
        QSqlQuery queryUpdate;
        queryUpdate.prepare("UPDATE MOVIES SET name= (:newName) WHERE name = (:oldName)");
        queryUpdate.bindValue(":newName", newName);
        queryUpdate.bindValue(":oldName", oldName);
        if(queryUpdate.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "update movie failed: " << queryUpdate.lastError();
        }
    }
    return success;
}


bool db_manager::removeMovie(const QString &name)
{
    bool success = false;
    if(!name.isEmpty() ){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM MOVIES WHERE name = (:name)");
        queryDelete.bindValue(":name", name);

        if(queryDelete.exec()){
            success = true;
        }
        else
        {
            qDebug() << "delete movie failed: " << queryDelete.lastError();
        }
    }
    return success;
}

QList<RoomDTO> db_manager::getRooms(const QString &name)
{
    QList<RoomDTO> rooms;
    QSqlQuery query;
    query.prepare("SELECT * FROM ROOMS where roomId not in (SELECT roomId FROM MOVIES where name = (:name) and MOVIES.roomId not NULL);");
    query.bindValue(":name", name);
    query.exec();

    int roomId= query.record().indexOf("roomId");
    int nameId= query.record().indexOf("name");
    int placesId = query.record().indexOf("places");

    while (query.next())
    {
        RoomDTO room;
        room.setId(query.value(roomId).toInt());
        room.setName(query.value(nameId).toString());

        QString placesStr = query.value(placesId).toString();
//        int places[placesStr.length()/2];
//        int *a{makeList(placesStr, places)};
        room.setCount(placesStr.length()/2);

        rooms.append(room);
    }
    return rooms;
}


QList<RoomDTO> db_manager::getRooms()
{
    QList<RoomDTO> rooms;
    QSqlQuery query("SELECT * FROM ROOMS");

    int nameId= query.record().indexOf("name");
    int placesId = query.record().indexOf("places");

    while (query.next())
    {
        RoomDTO room;
        room.setName(query.value(nameId).toString());

        QString placesStr = query.value(placesId).toString();
//        int places[placesStr.length()/2];
//        int *a{makeList(placesStr, places)};
        room.setCount(placesStr.length()/2);

        rooms.append(room);
    }
    return rooms;
}

bool db_manager::addRoom(const QString &name, const int &places)
{
    bool success = false;

    int arr[places];
    for(size_t i = 0; i < (sizeof(arr)/sizeof(*arr)); i++)
        arr[i]=0;


    if (!name.isEmpty() && places != 0){
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO ROOMS (name, places) VALUES (:name, :places)");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":places", stringify(arr, places));

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add room failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add room failed: name and places cannot be empty";
    }

    return success;
}

bool db_manager::editRoom(const QString &oldName, const QString &newName, const int &newCount)
{
    bool success = false;
    if(!newName.isEmpty() && !oldName.isEmpty() && newCount != 0){

        QSqlQuery queryUpdate;
        int arr[newCount];
        for(size_t i = 0; i < (sizeof(arr)/sizeof(*arr)); i++)
            arr[i]=0;

        queryUpdate.prepare("UPDATE ROOMS SET name= (:newName), places= (:places) WHERE name = (:oldName)");
        queryUpdate.bindValue(":newName", newName);
        queryUpdate.bindValue(":places", stringify(arr, newCount));
        queryUpdate.bindValue(":oldName", oldName);

        if(queryUpdate.exec()){
            success = true;
        }
        else {
            qDebug() << "update movie failed: " << queryUpdate.lastError();
        }
    }
    return success;
}

bool db_manager::removeRoom(const QString &name)
{
    bool success = false;
    if(!name.isEmpty() ){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM ROOMS WHERE name = (:name)");
        queryDelete.bindValue(":name", name);

        if(queryDelete.exec()){
            success = true;
        }
        else
        {
            qDebug() << "delete room failed: " << queryDelete.lastError();
        }
    }
    return success;
}

int db_manager::getRoomIdByName(const QString &name)
{
    int roomId = 0;
    if(!name.isEmpty()){

        QSqlQuery query;
        query.prepare("SELECT * FROM ROOMS WHERE name = (:name)");
        query.bindValue(":name", name);

        if(query.exec()){
            int room = query.record().indexOf("roomId");
            if(query.next()){
                roomId = query.value(room).toInt();
            }
        }
        else {
            qDebug() << "getRoomIdByName failed: " << query.lastError();
        }
    }
    return roomId;
}


QString db_manager::stringify(int arr[], int size)
{
    string str = "";
    for (int i = 0; i < size; i++){
        str += std::to_string(arr[i]);
        str += ",";
        qDebug() << i << ", ";
    }
    qDebug() << Qt::endl;
    return QString::fromStdString(str);
}


int * db_manager::makeList(const QString &list, int *arr)
{
    int len = list.length();

    for(int i = 0; i<len/2; i+=2){
        arr[i] = list.toStdString()[i]- '0';
        qDebug() << arr[i] << ", ";
    }
    qDebug() << Qt::endl;
    return arr;
}


int db_manager::getFreePlaces(QString &places)
{
    int count = 0;

      for (int i = 0; i < places.size(); i++)
        if (places[i] == '0') count++;

      return count;
}


QList<MovieRoomDTO> db_manager::getMovieList(const QString &name)
{
    QList<MovieRoomDTO> rooms;
    QSqlQuery query;
    query.prepare("SELECT MOVIES.movieId, MOVIES.name, MOVIES.date, ROOMS.name, ROOMS.places from MOVIES inner join ROOMS on ROOMS.roomId = MOVIES.roomId WHERE MOVIES.name = (:name);");
    query.bindValue(":name", name);



    if (query.exec()){

        int movieId = query.record().indexOf("movieId");
        int movieNameId= query.record().indexOf("name");
        int dateId = query.record().indexOf("date");
        int roomName = query.record().indexOf("ROOMS.name");
        int roomPlaces = query.record().indexOf("ROOMS.places");

        while (query.next()){
            MovieRoomDTO room;
            room.setMovieId(query.value(movieId).toString());
            room.setName(query.value(movieNameId).toString());
            room.setRoom(query.value(roomName).toString());
            room.setTime(query.value(dateId).toString());


            QString places = query.value(roomPlaces).toString();
            room.setPlaces(QString::number(places.length()/2));
            room.setFreePlaces(QString::number(getFreePlaces(places)));

            rooms.append(room);
        }
    } else {
        qDebug() << "get movie list failed: " << query.lastError();
    }
    return rooms;
}


bool db_manager::addMovieRoom(const QString &name, const int &roomId, const QDateTime date){
    bool success = false;

    if (!name.isEmpty() || roomId == 0)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO MOVIES (name, date, roomId) VALUES (:name, :dateTime, :roomId);");
        queryAdd.bindValue(":name", name);
        queryAdd.bindValue(":dateTime", date.toString("yyyy-MM-dd hh:mm:ss"));
        queryAdd.bindValue(":roomId", roomId);

        if(checkIfRoomEmpty(date, roomId)){
            if(queryAdd.exec()) {
                success = true;
            }
            else {
                qDebug() << "add movieroom failed: " << queryAdd.lastError();
            }
        }

    }
    else {
        qDebug() << "add movieroom failed: name cannot be empty";
    }

    return success;
}

bool db_manager::editMovieRoom(const int &movieId, const int &roomId, const QDateTime date)
{
    bool success = false;
    if(movieId != 0){

        QSqlQuery queryUpdate;
        queryUpdate.prepare("UPDATE MOVIES SET date= (:newDate) WHERE movieId = (:movieId)");

        queryUpdate.bindValue(":newDate", date.toString("yyyy-MM-dd hh:mm:ss"));
        queryUpdate.bindValue(":movieId", movieId);

        if(checkIfRoomEmpty(date, roomId)){
            if(queryUpdate.exec()){
                success = true;
            }
            else {
                qDebug() << "editMovieRoom failed: " << queryUpdate.lastError();
            }
        }

    }
    return success;
}

bool db_manager::removeMovieRoom(const int &movieId)
{
    bool success = false;
    if(movieId != 0){
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM MOVIES WHERE movieId = (:id)");
        queryDelete.bindValue(":id", movieId);

        if(queryDelete.exec()){
            success = true;
        }
        else
        {
            qDebug() << "removeMovieRoom failed: " << queryDelete.lastError();
        }
    }
    return success;
}

bool db_manager::checkIfRoomEmpty(const QDateTime date, const int &roomId)
{

    QDateTime toTime = date.addSecs(3600);
    QDateTime fromTime = date.addSecs(-3600);
    bool success = true;

    if (roomId != 0)
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM MOVIES WHERE date between (:fromTime) and (:toTime) and roomId = (:roomId);");

        query.bindValue(":fromTime", fromTime.toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(":toTime", toTime.toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(":roomId", roomId);

        if(query.exec()) {
            if (query.next()) {
                qDebug() <<  query.value(query.record().indexOf("movieId"));
                qDebug() <<  query.value(query.record().indexOf("name"));
                success = false;
            }
        }
        else {
            qDebug() << "checkIfRoomEmpty failed: " << query.lastError();
        }
    } else
    {
        qDebug() << "checkIfRoomEmpty failed: name cannot be empty";
    }

    return success;
}

QList<QChar> db_manager::getPlaces(const int &movieId)
{
    QList<QChar> places;
    if(movieId != 0){
        QSqlQuery query;
        query.prepare("SELECT M.movieId, R.roomId, R.places from MOVIES M INNER JOIN ROOMS R on R.roomId = M.roomId where M.movieId = (:movieId);");
        query.bindValue(":movieId", movieId);

        if (query.exec()){
            int placesDB = query.record().indexOf("places");

            while (query.next()){
                QString plc = query.value(placesDB).toString();
                for(size_t i = 0; i < plc.length(); i+=2){
                    if(plc.at(i) == '0' || plc.at(i) == '1'){
                        places.append(plc.at(i));
                    }
                }
            }
        }
    }
    return places;
}

bool db_manager::unreserve(const int &movieId, const int &placeNum)
{
    bool success = false;
    QString string;
    if(movieId != 0){
        QSqlQuery query;
        query.prepare("SELECT M.movieId, R.roomId, R.places from MOVIES M INNER JOIN ROOMS R on R.roomId = M.roomId where M.movieId = (:movieId);");
        query.bindValue(":movieId", movieId);

        if (query.exec()){
            int placesDB = query.record().indexOf("places");
            while (query.next()){
                string = query.value(placesDB).toString();
            }
        }


        if((string.length()/2) > placeNum){
            string[placeNum*2] = '0';

            QSqlQuery queryUpdate;
            queryUpdate.prepare("UPDATE ROOMS SET places= (:places) WHERE roomId IS (SELECT roomId from MOVIES where movieId = (:movieId));");
            queryUpdate.bindValue(":places", string);
            queryUpdate.bindValue(":movieId", movieId);
            if(queryUpdate.exec()){
                        success = true;
            }
            else {
                qDebug() << "update movie failed: " << queryUpdate.lastError();
            }
        }else{
            success = true;
        }
    }
    return success;
}


bool db_manager::reserve(const int &movieId, const int &placeNum)
{
    bool success = false;
    QString string;
    if(movieId != 0){
        QSqlQuery query;
        query.prepare("SELECT M.movieId, R.roomId, R.places from MOVIES M INNER JOIN ROOMS R on R.roomId = M.roomId where M.movieId = (:movieId);");
        query.bindValue(":movieId", movieId);

        if (query.exec()){
            int placesDB = query.record().indexOf("places");
            while (query.next()){
                string = query.value(placesDB).toString();
            }
        }

        if((string.length()/2) > placeNum){
            string[placeNum*2] = '1';

            QSqlQuery queryUpdate;
            queryUpdate.prepare("UPDATE ROOMS SET places= (:places) WHERE roomId IS (SELECT roomId from MOVIES where movieId = (:movieId));");
            queryUpdate.bindValue(":places", string);
            queryUpdate.bindValue(":movieId", movieId);
            if(queryUpdate.exec()){
                        success = true;
            }
            else {
                qDebug() << "update movie failed: " << queryUpdate.lastError();
            }
        }else{
            success = true;
        }
    }
    return success;
}



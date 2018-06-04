#include "globals.h"


QString VERSION = "0.1.2.0";
QString COPYRIGHT = "\nDawnlight Search " + VERSION + "\n\n" + "Copyright © 2018 ChG Hou\n";

// TODO: use correct open source license
// Qt:              GNU Lesser General Public License (LGPL) version 3
// KDE Frameworks:  LGPL

QString ORGANIZATION_NAME = "Dawnlight_Search";
QString ALLICATION_NAME = "Dawnligh_Search";
int MOUNT_STATE_UPDATE_INTERVAL;
int ROWID_UPDATE_INTERVAL;
int DB_UPDATE_INTERVAL;
bool USE_MFT_PARSER_CPP;
bool USE_MFT_PARSER;
QString DATETIME_FORMAT = "d/M/yyyy h:m:s";

bool SKIP_DIFF_DEV;
QString SIZE_UNIT;
bool INSTANT_SEARCH;
QStringList EXCLUDED_UUID;
// TODO: check this
QStringList DEFAULT_EXCLUDED_UUID = { "0:0","0:1" };


const QUERY_HEADER_class QUERY_HEADER;
DB_HEADER_class DB_HEADER;
UUID_HEADER_class UUID_HEADER;
QString PATH_OF_SETTING_FILE=QFileInfo(QSettings(QSettings::IniFormat, QSettings::UserScope, ORGANIZATION_NAME,
                                                       ALLICATION_NAME).fileName()).path();
QString DATABASE_FILE_NAME= QSettings(QSettings::IniFormat, QSettings::UserScope,
                                      ORGANIZATION_NAME, ALLICATION_NAME).value("Database_File_Name",
                                                                                QDir(PATH_OF_SETTING_FILE).filePath("files.db")
                                                                                ).toString();
QString TEMP_DB_NAME=QSettings(QSettings::IniFormat, QSettings::UserScope,
                              ORGANIZATION_NAME, ALLICATION_NAME).value("Temp_Database_File_Name",
                                                                        QDir(PATH_OF_SETTING_FILE).filePath("temp_db.db")
                                                                        ).toString();
//QStringList UUID_HEADER_LABEL = {
//    QCoreApplication::translate("ui","Search"), QCoreApplication::translate("ui","Mount Path"), QCoreApplication::translate("ui","Label"), QCoreApplication::translate("ui","UUID"),
//                         QCoreApplication::translate("ui","Alias"), QCoreApplication::translate("ui","FS Type"), QCoreApplication::translate("ui","Dev name"),
//                        QCoreApplication::translate("ui","Major Device Num"), QCoreApplication::translate("ui","Minor Device Num"), QCoreApplication::translate("ui","Items"),
//                         QCoreApplication::translate("ui","Update"),QCoreApplication::translate("ui","Progress")
//};
QStringList UUID_HEADER_LABEL = {
    "Search", "Mount Path", "Label", "UUID",
                         "Alias", "FS Type", "Dev name",
                        "Major Device Num", "Minor Device Num", "Items",
                         "Update","Progress"
};

QStringList UUID_HEADER_LIST = {"included", "path", "label", "uuid","alias", "fstype", "name",
                                "major_dnum", "minor_dnum", "rows", "updatable"};
QStringList DB_HEADER_LIST = {"Filename", "Path", "Size", "IsFolder","Extension",
                                "atime", "mtime", "ctime"  };
QStringList DB_HEADER_LABEL = {"Filename", "Path", "Size", "Is Folder","Extension",
                                "Access Time", "Modify Time", "Change Time"  };
QStringList QUERY_HEADER_LIST = {"Filename", "Path", "Size", "IsFolder",
                                 "atime", "mtime", "ctime"};

//QUERY_HEADERaaa.atime = 1;
//QUERY_HEADERaaa.atime=1;

int Query_Text_ID = 0;
long CURRENT_MODEL_ITEMS = 0;
int QUERY_THREAD_NUMBER = 1;
 long PROGRESS_STEP = 1000;
unsigned long QUERY_CHUNK_SIZE = 10000;
unsigned long QUERY_SQL_QUEUE_TOTAL_LENGTH=1;

unsigned int MATCH_OPTION = 1;
bool CASE_SENSTITIVE = false;
unsigned long QUERY_LIMIT = 100;
QSet<QPair<bool,QString >>  HIGHLIGHT_WORDS_NAME;
QSet<QPair<bool,QString >>  HIGHLIGHT_WORDS_PATH;
long MODEL_MAX_ITEMS = 3000;


bool COMPRESS_DB_FILE = false;
bool DB_READ_ONLY_FLAG = false;
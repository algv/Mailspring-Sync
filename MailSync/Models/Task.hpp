//
//  Folder.hpp
//  MailSync
//
//  Created by Ben Gotow on 6/17/17.
//  Copyright © 2017 Foundry 376. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <stdio.h>
#include <string>
#include "json.hpp"
#include "spdlog/spdlog.h"

#include "MailModel.hpp"
#include "MailStore.hpp"
#include <MailCore/MailCore.h>

using json = nlohmann::json;
using namespace std;
using namespace mailcore;

class Task : public MailModel {
    MailStore * store;
    shared_ptr<spdlog::logger> logger;
    
public:
    static string TABLE_NAME;

    Task(json json);
    Task(SQLite::Statement & query);
  
    json & data();
    string tableName();
    string constructorName();
    string status();
    void setStatus(string s);

    vector<string> columnsForQuery();
    void bindToQuery(SQLite::Statement & query);
};

#endif /* Task_hpp */

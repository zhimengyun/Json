#include "jsoncpp/json.h"
#include "iostream"

void json_sample()
{
  Json::Value root;

  root["Types"] = Json::Value("名号");
	root["Types"] = Json::Value("人物");
	root["Attributes"] = Json::Value("生年");
	root["Attributes"] = Json::Value("国别");

  std::cout << "Json::Value size: " << root.size() << std::endl;
  std::cout << "Normal Json::Value: " << root << std::endl;
}

//json以 key自动排序
void json_string()
{
  Json::Value root;
	Json::FastWriter fast;
	Json::Value m_exploit;

  root["roleId"] = 10009;
	root["exploit"] = 10376;
	m_exploit.append(root);
	root["roleId"] = 10006;
	root["exploit"] = 2447;
	m_exploit.append(root);

  std::string sRoot = fast.write(root);
	std::cout << sRoot << std::endl;

  std::string temp = sRoot;

  sRoot.erase(sRoot.end()-1);
	std::cout << sRoot.c_str() << std::endl;

  if (temp == sRoot)
  {
    std::cout << "this is equal~" << std::endl;
  }

  std::cout << "json root[\"roleId\"]: " << root["roleId"] << "json root[\"exploit\"]: " << root["exploit"] << std::endl;

  std::cout << "Array Json::Value: " << m_exploit << std::endl;

  std::string sExploit = fast.write(m_exploit);
  std::cout << sExploit << std::endl;

  sExploit.erase(sExploit.end()-1);
	std::cout << sExploit.c_str() << std::endl;

  //Json parse
  Json::Value json_value_j;
  Json::Reader json_reader_j;
  if (json_reader_j.parse(sExploit, json_value_j))
  {
    std::cout << "json_value_j: " << json_value_j;
    int nSize = static_cast<int>(json_value_j.size());
    for(int i = 0; i < nSize; ++i)
    {
      int roleId = json_value_j[i]["roleId"].asInt();
      std::cout << "roleId: " << roleId << std::endl;
    }
  }
}

//Json parse
void json_complex()
{
  Json::Value root;
	Json::FastWriter fast;
	Json::Value m_exploit;

  root["ID"] = 1;
	root["Season"] = 1;
  root["MassList"] = 1000;
	m_exploit.append(root);
  root["ID"] = 2;
	root["Season"] = 99;
  root["MassList"] = 201;
	m_exploit.append(root);

  std::string sRoot = fast.write(root);
	std::cout << sRoot << std::endl;
  std::string sExploit = fast.write(m_exploit);
	std::cout << sExploit << std::endl;

  Json::Value json_value_j;
  Json::Reader json_reader_j;
  if (json_reader_j.parse(sExploit, json_value_j))
  {
    std::cout << "json_value_j: " << json_value_j;
    int nSize = static_cast<int>(json_value_j.size());
    for(int i = 0; i < nSize; ++i)
    {
      int MassList = json_value_j[i]["MassList"].asInt();
      std::cout << "MassList: " << MassList << std::endl;
    }
  }
}

int main()
{
  json_sample();
  json_string();
  json_complex();

  return 0;
}

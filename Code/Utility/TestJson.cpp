// ����Json�ļ���д����json for modern C++�ķ�ʽ
#include "TestJson.h"
#include <unordered_map>
#include "json.hpp"
#include <fstream>


void TestJson::CreateJson(const std::string& json_path)
{
	nlohmann::json json;
	json["MapInfo"] = nlohmann::json::object();

	std::ofstream ofs(json_path);
	ofs << json;
	ofs.close();
}

bool TestJson::WriteToJson(const std::string& json_path)
{
	std::ifstream ifs(json_path);
	if (ifs.fail())
	{
		CreateJson(json_path);
		ifs.open(json_path);
	}

	nlohmann::json json;

	try
	{
		ifs >> json;
	}
	catch (nlohmann::detail::exception& error)
	{
		ifs.close();
		CreateJson(json_path);
		ifs.open(json_path);
		ifs >> json;
	}
	ifs.close();

	json["Name"] = "Will";
	json["Age"] = "18";
	json["Num"] = "17956455356";

	std::ofstream ofs(json_path);
	ofs << json_path;
	ofs.close();
	return true;
}

void TestJson::JsonBase()
{
	nlohmann::json json;

	{
		//���һ���洢Ϊdouble������
		json["pi"] = 3.141;

		// ���һ������ֵ 
		json["happy"] = true;

		// ���һ���洢Ϊstd :: string���ַ���
		json["name"] = "Niels";

		// �ڶ�������Ӷ���
		json["answer"]["everything"] = 42;

		//���һ�����飬��洢Ϊstd::vector��ʹ�ó�ʼ���б�
		json["list"] = { 1, 0, 2 };

		// ��һ�������������һ������
		json["object"] = { {"currency", "USD"}, {"value", 42.99} };

		//����һ��������
		json["null_array"] = nlohmann::json::array();
		json["null_array"].emplace_back(1);
		json["null_array"].emplace_back("asd");

		// ����һ���ն�������ַ�ʽ
		json["null_obj"] = nlohmann::json({});
		json["null_object"] = nlohmann::json::object();
	}

	std::ofstream ofs("./test.json");
	ofs << json;
	ofs.close();
}

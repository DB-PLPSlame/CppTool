// ����Json�ļ���д����json for modern C++�ķ�ʽ
#pragma once
#include <string>

class TestJson
{
public:
	TestJson() = default;
	~TestJson() = default;

	static void CreateJson(const std::string& json_path);
	static bool WriteToJson(const std::string& json_path);

	static void JsonBase();
};


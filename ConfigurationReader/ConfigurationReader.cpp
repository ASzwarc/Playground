#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

class ConfigurationReader
{
public:
	ConfigurationReader()
	{}
	void readDataFrom(std::string fileName)
	{
		std::string readLine;
		std::ifstream file(fileName);
		if(file.is_open())
		{
			while(std::getline(file, readLine))
			{
				std::vector<std::string> tokens(3);
				std::cout << readLine << std::endl;
				std::stringstream inbuf(readLine);
				for(int i = 0; std::getline(inbuf, tokens[i], ' ') && i < 3; i++)
				{
				}
				for(auto it = tokens.cbegin(); it != tokens.cend(); ++it)
				{
					std::cout << *it << std::endl;
				}
				if(tokens[2] == "true")
				{
					boolParametersMap_[tokens[0]] = true;
				}
				else if(tokens[2] == "false")
				{
					boolParametersMap_[tokens[0]] = false;
				}
				else
				{
					try
					{
						int value = std::stoi(tokens[2]);
						intParametersMap_[tokens[0]] = value;
					}
					catch(const std::invalid_argument& e)
					{
						std::cout << "caught invalid argument exception: " << e.what() << std::endl;
					}
				}
			}
			file.close();
			for(auto it = boolParametersMap_.cbegin(); it != boolParametersMap_.cend(); ++it)
			{
				std::cout << std::boolalpha << it->first << " " << it->second << std::endl;
			}
			for(auto it = intParametersMap_.cbegin(); it != intParametersMap_.cend(); ++it)
			{
				std::cout << it->first << " " << it->second << std::endl;
			}
		}
	}

private:
	std::map<std::string, int> intParametersMap_;
	std::map<std::string, bool> boolParametersMap_;
};

int main()
{
	ConfigurationReader reader;
	reader.readDataFrom("configuration_parameters.txt");
	return 0;
}
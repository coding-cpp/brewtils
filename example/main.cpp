#include <iostream>

#include <brewtils/base64.h>
#include <brewtils/os.h>
#include <brewtils/string.h>
#include <brewtils/url.h>
#include <brewtils/uuid.h>

void hr() {
  std::cout << std::endl
            << "----------------------------------------" << std::endl
            << std::endl;
}

int main(int argc, char **argv) {

  hr();

  std::cout << brewtils::uuid::v4() << std::endl;
  hr();

  std::cout << brewtils::uuid::v5("6ba7b810-9dad-11d1-80b4-00c04fd430c8",
                                  "hello world")
            << std::endl;
  hr();

  std::string data =
      "   {\"widget\" : {\"debug\" : \"on\",      \"window\" : {        "
      "\"title\" "
      ": \"Sample Konfabulator Widget\",        \"name\" : \"main_window\",    "
      "    \"width\" : 500,        \"height\" : 500      },      \"image\" : { "
      "       \"src\" : \"Images/Sun.png\",        \"name\" : \"sun1\",        "
      "\"hOffset\" : 250,        \"vOffset\" : 250,        \"alignment\" : "
      "\"center\"      },      \"text\" : {        \"data\" : \"Click Here\",  "
      "      \"size\" : 36,        \"style\" : \"bold\",        \"name\" : "
      "\"text1\",        \"hOffset\" : 250,        \"vOffset\" : 100,        "
      "\"alignment\" : \"center\",        \"onMouseUp\" : \"sun1.opacity = "
      "(sun1.opacity / 100) * 90;\"      }    }  }   ";
  std::string encoded = brewtils::base64::encode(data);
  std::cout << encoded << std::endl;
  hr();

  std::string decoded = brewtils::base64::decode(encoded);
  std::cout << decoded << std::endl;
  hr();

  std::string trimmedData = brewtils::string::trim(data);
  std::cout << trimmedData << std::endl;
  hr();

  std::vector<std::string> strings = brewtils::string::split(data, " ");
  std::string joined = brewtils::string::join(strings, "");
  std::cout << joined << std::endl;
  hr();

  data = "https://www.google.com/search?q=hello+world";
  encoded = brewtils::url::encode(data);
  std::cout << encoded << std::endl;
  hr();

  decoded = brewtils::url::decode(encoded);
  std::cout << decoded << std::endl;
  hr();

  for (std::string file : brewtils::os::dir::list("/")) {
    std::cout << file << std::endl;
  }
  hr();

  return EXIT_SUCCESS;
}
import json
from datetime import date

html_file_path = "../SD-Card/index.html"

# generate h file
h_file = open("../src/Webserver/Website.h", "w+")
h_file.write("/*##############################################################################\n")
h_file.write("\n")
h_file.write("  THIS IS GENERATED CODE (use " + __file__ + ".ods)\n")
h_file.write("    ==> DO NOT EDIT MANUALLY !!!\n")
h_file.write("\n")
h_file.write("##############################################################################*/\n")
h_file.write("\n")
h_file.write("\n")
h_file.write("/*******************************************************************************\n")
h_file.write("Project   RoomLight\n")
h_file.write("\n")
h_file.write("  This is an OpenSource Project.\n")
h_file.write("  You can use, share or improve this project. If you improve this source code\n")
h_file.write("  please share with the comunity or at least with the author of the original\n")
h_file.write("  source code\n")
h_file.write("\n")
h_file.write("  Created " + date.today().strftime("%d. %B %Y") + " by MarkusNTrains\n")
h_file.write("================================================================================\n")
h_file.write("$HeadURL:  $\n")
h_file.write("$Id:  $\n")
h_file.write("*******************************************************************************/\n")
h_file.write("\n")
h_file.write("\n")
h_file.write("#ifndef _WEBSITE_H\n")
h_file.write("#define _WEBSITE_H\n")
h_file.write("\n")
h_file.write("\n")
h_file.write("//-----------------------------------------------------------------------------\n")
h_file.write("// includes\n")
h_file.write("#include <Ethernet.h>\n")
h_file.write("\n")
h_file.write("\n")
h_file.write("//----------------------------------------------------------------------------\n")
h_file.write("// Function Prototypes\n")
h_file.write("void Website_SendToClient(EthernetClient* client);\n")
h_file.write("\n")
h_file.write("\n")
h_file.write("\n")
h_file.write("#endif  // _WEBSITE_H\n")


# generate cpp file
cpp_file = open("../src/Webserver/Website.cpp", "w+")

cpp_file.write("/*##############################################################################\n")
cpp_file.write("\n")
cpp_file.write("  THIS IS GENERATED CODE (use " + __file__ + ".ods)\n")
cpp_file.write("    ==> DO NOT EDIT MANUALLY !!!\n")
cpp_file.write("\n")
cpp_file.write("##############################################################################*/\n")
cpp_file.write("\n")
cpp_file.write("\n")
cpp_file.write("/*******************************************************************************\n")
cpp_file.write("Project   RoomLight\n")
cpp_file.write("\n")
cpp_file.write("  This is an OpenSource Project.\n")
cpp_file.write("  You can use, share or improve this project. If you improve this source code\n")
cpp_file.write("  please share with the comunity or at least with the author of the original\n")
cpp_file.write("  source code\n")
cpp_file.write("\n")
cpp_file.write("  Created " + date.today().strftime("%d. %B %Y") + " by MarkusNTrains\n")
cpp_file.write("================================================================================\n")
cpp_file.write("$HeadURL:  $\n")
cpp_file.write("$Id:  $\n")
cpp_file.write("*******************************************************************************/\n")
cpp_file.write("\n")
cpp_file.write("\n")
cpp_file.write("//-----------------------------------------------------------------------------\n")
cpp_file.write("// includes\n")
cpp_file.write("#include \"Website.h\"\n")
cpp_file.write("\n")
cpp_file.write("\n")
cpp_file.write("//-----------------------------------------------------------------------------\n")
cpp_file.write("// This variant needs more flash but less heap\n")
cpp_file.write("// PROGMEM -> store data in flash\n")
cpp_file.write("//   to read out the stored data from PROGMEM use one macro of <avr/pgmspace.h>\n")
cpp_file.write("//   - e.g. (char*)pgm_read_word(&(PARAM_IN_PROGMEM))\n")
cpp_file.write("//   - or use memcpy_P\n")
cpp_file.write("//      data_type_t param_SRAM\n")
cpp_file.write("//      memcpy_P(&param_SRAM, &PARAM_IN_PROGMEM, sizeof(data_type_t))\n")
cpp_file.write("//   more infos: https://www.arduino.cc/reference/en/language/variables/utilities/progmem/\n")
cpp_file.write("\n")
cpp_file.write("// F Macro within println (exp.  println(F('Hello World'))) -> store string in flash\n")
cpp_file.write("\n")
cpp_file.write("\n")
cpp_file.write("//*****************************************************************************\n")
cpp_file.write("// description:\n")
cpp_file.write("//   Website_SendToClient\n")
cpp_file.write("//*****************************************************************************\n")
cpp_file.write("void Website_SendToClient(EthernetClient* client)\n")
cpp_file.write("{\n")

nof_lines = 0
max_line_length = 0;
with open(html_file_path) as file:
    for line in file:
        line_str = ((line.rstrip()).lstrip(' \t'))
        line_str = json.dumps(line_str)
        # print(line_str)
        nof_lines += 1
        cpp_file.write("    client->println(F(" + line_str + "));\n")

        if max_line_length < len(line_str):
            max_line_length = len(line_str)

# add footer
from datetime import date
footer_a = []
footer_a.append("<html>")
footer_a.append("<footer>")
footer_a.append("    <div>")
footer_a.append("        <hr>")
footer_a.append("        <div id=\"footer_version\" style=\"float:left\">vX.Y</div>")
footer_a.append("        &nbsp;&nbsp;|&nbsp;&nbsp;" + date.today().strftime("%d. %B %Y") + " &nbsp; &copy; MarkusNTrains")
footer_a.append("        <a href='mailto:markusntrains@gmx.ch'>E-Mail</a>")
footer_a.append("    </div>")
footer_a.append("</footer>")
footer_a.append("</html>")

for line in footer_a:
    line_str = ((line.rstrip()).lstrip(' \t'))
    line_str = json.dumps(line_str)
    # print(line_str)
    nof_lines += 1
    cpp_file.write("    client->println(F(" + line_str + "));\n")

    if max_line_length < len(line_str):
        max_line_length = len(line_str)

cpp_file.write("}\n")
cpp_file.write("\n")

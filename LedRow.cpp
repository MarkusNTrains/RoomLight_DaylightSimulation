/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 24. August 2020 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/


//-----------------------------------------------------------------------------
// includes
#include "LedRow.h"


//-----------------------------------------------------------------------------
// typedef


//-----------------------------------------------------------------------------
// define


//-----------------------------------------------------------------------------
// const
const uint16_t LED_MATRIX_LUT[LED_ROW_NOF][LED_ROW_LENGTH] PROGMEM = {  // PROGMEM -> store data in flash
    { 600,  600,  601,  602,  603,  604,  605,  606,  607,  608,  609,  610,  611,  612,  613,  614,  615,  616,  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,  645,  646,  647,  648,  649,  650,  651,  652,  653,  654,  655,  656,  657,  658,  659,  660,  661,  662,  663,  664,  665,  666,  667,  668,  669,  670,  671,  672,  673,  674,  675,  676,  677,  678,  679,  680,  681,  682,  683,  684,  685,  686,  696,  697,  698,  699,  700,  701,  702,  703,  704,  705,  706,  707,  708,  709,  710,  711,  712,  713,  714,  715,  716,  717,  718,  719,  720,  721,  722,  723,  724,  725,  726,  727,  728,  729,  730,  731,  732,  733,  734,  735,  736,  737,  738,  739,  740,  741,  742,  751,  752,  753,  754,  755,  756,  757,  758,  759,  760,  761,  762,  763,  764,  765,  766,  767,  768,  769,  770,  771,  772,  773,  774,  775,  776,  777,  778,  779,  780,  781,  782,  783,  784,  785,  786,  787,  788,  789,  790,  791,  792,  793,  794,  795,  796,  797,  798,  799,  800,  801,  802,  803,  804,  805,  806,  807,  808,  809,  810,  811,  812,  813,  814,  815,  816,  817,  818,  819,  820,  821,  822,  823,  824,  825,  826,  827,  828,  829,  830,  831,  832,  833,  834,  835,  836,  837,  838,  839,  840,  841,  842,  843,  844,  845,  846,  847,  848,  849,  850,  851,  852,  853,  854,  855,  856,  857,  858,  859,  860,  861,  862,  863,  864,  865,  866,  867,  868,  869,  870,  871,  872,  873,  874,  875,  876,  877,  878,  879,  880,  881,  882,  883,  884,  885,  886,  887,  888,  889,  890,  891,  892,  893,  894,  895,  896,  897,  898,  899,  899},
    { 599,  583,  582,  581,  580,  579,  578,  577,  576,  575,  574,  573,  572,  571,  570,  569,  568,  567,  566,  565,  564,  563,  562,  561,  560,  559,  558,  557,  556,  555,  554,  553,  552,  551,  550,  549,  548,  547,  546,  545,  544,  543,  542,  541,  540,  539,  538,  537,  536,  535,  534,  533,  532,  531,  530,  529,  528,  527,  526,  525,  524,  523,  522,  521,  520,  519,  518,  517,  516,  515,  514,  513,  512,  511,  510,  509,  508,  507,  506,  505,  504,  503,  502,  501,  500,  499,  498,  497,  496,  495,  494,  493,  492,  491,  490,  489,  488,  487,  486,  485,  484,  483,  482,  481,  480,  479,  478,  477,  476,  475,  474,  473,  472,  471,  470,  469,  468,  467,  466,  465,  464,  463,  462,  461,  460,  459,  458,  457,  456,  455,  454,  453,  452,  451,  450,  449,  448,  447,  446,  445,  444,  443,  442,  441,  440,  439,  438,  437,  436,  435,  434,  433,  432,  431,  430,  429,  428,  427,  426,  425,  424,  423,  422,  421,  420,  419,  418,  417,  416,  415,  414,  413,  412,  411,  410,  409,  408,  407,  406,  405,  404,  403,  402,  401,  400,  399,  398,  397,  396,  395,  394,  393,  392,  391,  390,  389,  388,  387,  386,  385,  384,  383,  382,  381,  380,  379,  378,  377,  376,  375,  374,  373,  372,  371,  370,  369,  368,  367,  366,  365,  364,  363,  362,  361,  360,  359,  358,  357,  356,  355,  354,  353,  352,  351,  350,  349,  348,  347,  346,  345,  344,  343,  342,  341,  340,  339,  338,  337,  336,  335,  334,  333,  332,  331,  330,  329,  328,  327,  326,  325,  324,  323,  322,  321,  320,  319,  318,  317,  316,  315,  314,  313,  312,  311,  310,  309,  308,  307,  306,  305,  304,  303,  302,  301,  300},
    { 0,  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,  170,  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,  197,  198,  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,  253,  254,  255,  256,  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,  299},
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,  168,  169,  170,  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,  197,  198,  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,  253,  254,  255,  256,  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,  284}
};

//-----------------------------------------------------------------------------
// static module variable



//*****************************************************************************
// description:
//   constructor
//*****************************************************************************
LedRow::LedRow(Adafruit_NeoPixel* led_strip_p, uint8_t row_idx)
{
    this->m_led_strip_p = led_strip_p;
    this->m_row_idx = row_idx;
}


//*****************************************************************************
// description:
//   destructor
//*****************************************************************************
LedRow::~LedRow()
{
}


//*****************************************************************************
// description:
//   Returns led idx from loock up table
//*****************************************************************************
uint16_t LedRow::GetLedIdxOfLut(uint16_t idx)
{
    return pgm_read_word_near(&LED_MATRIX_LUT[this->m_row_idx][idx]);
}


//*****************************************************************************
// description:
//   Send the updated pixel colors to the hardware.
//*****************************************************************************
void LedRow::Show(void)
{
    this->m_led_strip_p->show();    
}


//*****************************************************************************
// description:
//   Set Pixel
//*****************************************************************************
void LedRow::SetPixel(uint16_t idx, uint32_t color)
{
    this->m_led_strip_p->setPixelColor(this->GetLedIdxOfLut(idx), color);
}


//*****************************************************************************
// description:
//   Show White Pixel
//*****************************************************************************
void LedRow::SetPixel(uint16_t start_idx, uint16_t width, uint16_t space, uint16_t nof_repeat, uint32_t color)
{
    uint16_t px = 0;
    uint16_t idx = 0;
    uint16_t cnt = 0;
    uint16_t offset = 0;
    uint16_t nof_px_to_fill = 0;
    
    if (start_idx >= LED_ROW_LENGTH)
    { return; }
    
    if ((start_idx + width) > LED_ROW_LENGTH)
    {
        width = LED_ROW_LENGTH - start_idx;
    }

    width -= 1;

    offset = start_idx;
    for (cnt = 0; cnt < nof_repeat; cnt++)
    {
        /*for (px = 0; px < width; px++)
        {
            // check if position is further than the rowlength
            if ((offset + px) >= this->m_length) { break; }
            
            idx = offset + px;
        Serial.println(idx);
            this->m_led_strip_p->setPixelColor(this->m_lookup_table_p[idx], color);    
        }*/
        if (this->GetLedIdxOfLut(offset) <= this->GetLedIdxOfLut(offset + width))
        {
            idx = this->GetLedIdxOfLut(offset);
            nof_px_to_fill = (this->GetLedIdxOfLut(offset + width) - idx) + 1;
        }
        else
        {
            idx = this->GetLedIdxOfLut((offset + width));
            nof_px_to_fill = (this->GetLedIdxOfLut(offset) - idx) + 1;  
        }
        this->m_led_strip_p->fill(color, idx, nof_px_to_fill);
      
        offset += space + width;      
        // check if offset is further than the rowlength
        if (offset >= LED_ROW_LENGTH) { break; }
    }
}

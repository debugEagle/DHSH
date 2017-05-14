#include "stdafx.h"
#include "ResText.h"
#include <MyTools/Log.h>

#define _SELF L"ResText.cpp"
BOOL CResText::Initialize()
{
	SetErrorPtr([](_In_ CONST std::wstring& wsErrText)
	{
		StopGame;
		LOG_MSG_CF(L"UnExist RelfexStruct, Text=%s", wsErrText.c_str());
	});

	RegisterResNpcMapText();

	return TRUE;
}

VOID CResText::RegisterResNpcMapText()
{
	CONST static std::vector<ResNpcMapPointText> Vec = 
	{
		{ L"��Ӧ����������", L"Ӧ�츮", L"Ӧ�츮", Point(153, 223) },
		{ L"��������������", L"������", L"������", Point(80, 56) },
		{ L"���塿��������", L"�����", L"�����", Point(150, 60) },
		{ L"�Ͻ������", L"�����", L"�����", Point(147, 101) },
		{ L"������", L"�����", L"�����", Point(93, 39) },
		{ L"��С��", L"�����", L"�����", Point(170, 141) },
		{ L"����", L"Ӧ�츮", L"Ӧ�츮", Point(432, 130) },
		{ L"�س���", L"Ӧ�츮", L"Ӧ�츮", Point(86, 302) },
		{ L"����������", L"������", L"������", Point(55, 121) },
		{ L"��÷", L"�������һ¥", L"�������һ¥", Point(47, 46) },
		{ L"������", L"������Ҷ�¥", L"������Ҷ�¥", Point(38, 55) },
		{ L"����", L"������", L"������", Point(14, 74) },
		{ L"���", L"â��ɽ´", L"â��ɽ´", Point(35, 103) },
		{ L"��ƿ��", L"�������һ¥", L"�������һ¥", Point(29, 60) },
		{ L"���", L"�������һ¥", L"�������һ¥", Point(22, 57) },
		{ L"������", L"�������һ¥", L"�������һ¥", Point(33, 46) },
		{ L"����ɮ��", L"Ӧ�츮", L"Ӧ�츮", Point(464, 138) },
		{ L"����Э��᳤��", L"Ӧ�츮", L"Ӧ�츮", Point(117, 74) },
		{ L"����", L"Ӧ�츮", L"Ӧ�츮", Point(233, 302) },
		{ L"�Ի�", L"Ӧ�츮", L"Ӧ�츮", Point(239, 305) },
		{ L"�ſ�Ŀ", L"Ӧ�츮����", L"Ӧ�츮����", Point(58, 32) },
		{ L"����", L"â��ɽ´", L"â��ɽ´", Point(130, 16) },
		{ L"����", L"�����", L"�����", Point(195, 71) },
		{ L"�����", L"����ɼҶ�¥", L"����ɼҶ�¥", Point(20, 16) },
		{ L"۩��", L"������", L"������", Point(83, 138) },
		{ L"����", L"���ʪ��", L"���ʪ��", Point(95, 20) },
		{ L"����ױ", L"�����", L"�����", Point(88, 81) },
		{ L"ˮ�����ָ��ʦ", L"�����", L"�����", Point(206, 28) },
		{ L"����峤��", L"�����", L"�����", Point(108, 36) },
		{ L"��ҽ����ȫ", L"�����", L"�����", Point(204, 137) },
		{ L"����С��", L"�����", L"�����", Point(230, 125) },
		{ L"СPP", L"������", L"������", Point(94, 132) },
		{ L"��å��", L"������", L"������", Point(151, 108) },
		{ L"����", L"������", L"������", Point(43, 89) },
		{ L"������", L"Ӧ�츮", L"Ӧ�츮", Point(18, 188) },
		{ L"ţ��", L"Ӧ�츮", L"Ӧ�츮", Point(351, 157) },
		{ L"�ʸ���", L"�����", L"�����", Point(210, 140) },
		{ L"��־", L"Ӧ�츮", L"Ӧ�츮", Point(345, 152) },
		{ L"ߴ������", L"�����", L"�����", Point(24, 54) },
		{ L"С����", L"�����", L"�����", Point(12, 125) },
		{ L"�Ʊ�", L"Ӧ�츮", L"Ӧ�츮", Point(207, 41) },
		{ L"������", L"Ӧ�츮", L"Ӧ�츮", Point(441, 134) },
		{ L"�˽���", L"������Ҷ�¥", L"������Ҷ�¥", Point(50, 46) },
		{ L"����", L"�����", L"�����", Point(87, 55) },
		{ L"����", L"������", L"������", Point(68, 84) },
		{ L"����", L"â��ɽ´", L"â��ɽ´", Point(80, 76) },
		{ L"�˸�", L"�����", L"�����", Point(146, 143) },
		{ L"�׺�", L"â��ɽ´", L"â��ɽ´", Point(167, 103) },
		{ L"��С��", L"�����", L"�����", Point(9, 77) },
		{ L"��С��", L"�����", L"�����", Point(14, 73) },
		{ L"��С��", L"�����", L"�����", Point(20, 70) },
		{ L"��ʤ", L"�����", L"�����", Point(204, 126) },
		{ L"����", L"Ӧ�츮����", L"Ӧ�츮����", Point(49, 26) },
		{ L"ţ��", L"Ӧ�춫��", L"Ӧ�춫��", Point(11, 35) },
		{ L"���", L"�񸮴�լ", L"�񸮴�լ", Point(42, 33) },
		{ L"�׻�", L"������", L"������", Point(169, 9) },
		{ L"���㹧", L"������", L"������", Point(49, 131) },
		{ L"����ϲ", L"������", L"������", Point(56, 134) },
		{ L"�ξ���", L"������", L"������", Point(123, 100) },
		{ L"����", L"Ӧ�춫��", L"Ӧ�춫��", Point(77, 46) },
		{ L"���", L"��������", L"��������", Point(126, 34) },
		{ L"��ĸ", L"�����", L"�����", Point(202, 30) },
		{ L"���", L"�����", L"�����", Point(189, 31) },
		{ L"�츻", L"Ӧ�츮", L"Ӧ�츮", Point(134, 211) },
		{ L"����", L"Ӧ�츮", L"Ӧ�츮", Point(431, 101) },
		{ L"�Ļ��ְ�", L"��������", L"��������", Point(122, 84) },
		{ L"�Ļ�����", L"��������", L"��������", Point(136, 81) },
		{ L"�Ļ����", L"��������", L"��������", Point(109, 94) },
		{ L"�Ļ��ܵ�", L"��������", L"��������", Point(131, 91) },
		{ L"ʷ��", L"μ�ݳ���", L"μ�ݳ���", Point(121, 53) },
		{ L"³����", L"μ�ݳ���", L"μ�ݳ���", Point(156, 113) },
		{ L"���϶�", L"Ӧ�츮", L"Ӧ�츮", Point(215, 35) },
		{ L"�����", L"Ӧ�츮", L"Ӧ�츮", Point(224, 41) },
		{ L"������", L"Ӧ�츮", L"Ӧ�츮", Point(192, 41) },
		{ L"�����", L"μ�ݳ���", L"μ�ݳ���", Point(43, 49) },
		{ L"������Ĺ���", L"Ұ����", L"Ұ����", Point(100, 19) },
		{ L"����", L"�꾩��", L"�꾩��", Point(275, 245) },
		{ L"����", L"����", L"����", Point(105, 81) },
		{ L"Ѧ��", L"����", L"����", Point(111, 77) },
		{ L"�ֳ�", L"����", L"����", Point(182, 16) },
		{ L"½ǫ", L"�꾩��", L"�꾩��", Point(256, 188) },
		{ L"����", L"���ݵ�", L"���ݵ�", Point(15, 115) },
		{ L"���", L"Ӧ�춫��", L"Ӧ�춫��", Point(172, 17) },
		{ L"�ν�", L"Ӧ�츮", L"Ӧ�츮", Point(249, 268) },
		{ L"��˳", L"Ӧ�춫��", L"Ӧ�춫��", Point(154, 20) },
		{ L"���ı�", L"Ӧ�츮", L"Ӧ�츮", Point(449, 140) },
		{ L"����", L"�꾩����", L"�꾩����", Point(125, 90) },
		{ L"����", L"�꾩����", L"�꾩����", Point(13, 71) },
		{ L"����", L"μ�ݳ���", L"μ�ݳ���", Point(25, 18) },
		{ L"����", L"���ɽ", L"���ɽ", Point(213, 96) },
		{ L"������", L"�꾩��", L"�꾩��", Point(213, 287) },
		{ L"ף��ׯ�Ƶ��ϰ�", L"μ�ݳ���", L"μ�ݳ���", Point(71, 36) },
		{ L"����", L"ʮ����", L"ʮ����", Point(141, 134) },
		{ L"����", L"ʮ����", L"ʮ����", Point(105, 52) },
		{ L"�ֺ�", L"�꾩��", L"�꾩��", Point(91, 218) },
		{ L"��͢��", L"μ�ݳ���", L"μ�ݳ���", Point(206, 54) },
		{ L"������", L"���ׯ", L"���ׯ", Point(228, 72) },
		{ L"����", L"���ݵ�", L"���ݵ�", Point(12, 57) },
		{ L"������", L"��ɽ", L"��ɽ", Point(38, 167) },
		{ L"����", L"�꾩��", L"�꾩��", Point(389, 178) },
		{ L"����", L"��ɽ", L"��ɽ", Point(184, 28) },
		{ L"���ӷ���", L"�꾩��", L"�꾩��", Point(324, 217) },
		{ L"¬����", L"�꾩��", L"�꾩��", Point(333, 66) },
		{ L"����", L"��̨ɽ��", L"��̨ɽ��", Point(73, 68) },
		{ L"ʯ��", L"��̨ɽ��", L"��̨ɽ��", Point(90, 127) },
		{ L"����", L"�꾩��", L"�꾩��", Point(327, 184) },
		{ L"��ʤ", L"�꾩��", L"�꾩��", Point(349, 173) },
		{ L"������", L"�꾩��", L"�꾩��", Point(165, 169) },
		{ L"��Ь", L"�����", L"�����", Point(187, 93) },
		{ L"����", L"�����", L"�����", Point(122, 135) },
		{ L"��Ȯ", L"�����", L"�����", Point(141, 24) },
		{ L"����", L"�����", L"�����", Point(28, 62) },
		{ L"����", L"���ɽ", L"���ɽ", Point(135, 130) },
		{ L"��ƽ", L"���ɽ", L"���ɽ", Point(156, 126) },
		{ L"���ĵ�", L"����", L"����", Point(289, 271) },
		{ L"����", L"����", L"����", Point(316, 243) },
		{ L"Ů�", L"����", L"����", Point(290, 31) },
		{ L"������", L"��ɽˮ��", L"��ɽˮ��", Point(57, 85) },
		{ L"���汣", L"��ɽ", L"��ɽ", Point(242, 115) },
		{ L"��Ӽ�", L"��ɽ", L"��ɽ", Point(287, 130) },
		{ L"����", L"��ɽ", L"��ɽ", Point(248, 66) },
		{ L"�ܰ�", L"��ɽ", L"��ɽ", Point(247, 73) },
		{ L"��ٴ", L"�꾩��", L"�꾩��", Point(187, 87) },
		{ L"��У", L"��ɽ", L"��ɽ", Point(39, 143) },
		{ L"���", L"�꾩��", L"�꾩��", Point(148, 189) },
		{ L"��̫ξ", L"�꾩��", L"�꾩��", Point(112, 129) },
		{ L"������", L"����ս��", L"����ս��", Point(113, 58) },
		{ L"Ү�ɹ���", L"����ս��", L"����ս��", Point(136, 78) },
		{ L"Ү�ɹ���", L"����ս��", L"����ս��", Point(144, 74) },
		{ L"Ү�ɵ���", L"����ս��", L"����ս��", Point(144, 31) },
		{ L"����", L"����ս��", L"����ս��", Point(55, 94) },
		{ L"����", L"����ս��", L"����ս��", Point(66, 90) },
		{ L"���ر�", L"����ս��", L"����ս��", Point(101, 44) },
		{ L"����", L"�꾩��", L"�꾩��", Point(307, 82) },
		{ L"����", L"��ɽ", L"��ɽ", Point(235, 155) },
		{ L"�λ���", L"�꾩��", L"�꾩��", Point(74, 13) },
		{ L"��Ѫ�����", L"������һ", L"������һ", Point(20, 21) },
		{ L"�����ƿ", L"��̨ɽ", L"��̨ɽ", Point(54, 49) },
		{ L"������", L"Ӧ�츮", L"Ӧ�츮", Point(357, 186) },
		{ L"���ʸ�", L"Ӧ�츮", L"Ӧ�츮", Point(355, 205) },
		{ L"����ܵ�", L"Ӧ�츮", L"Ӧ�츮", Point(284, 117) },
		{ L"����", L"Ӧ�츮", L"Ӧ�츮", Point(12, 95) },
		{ L"�쵶�ֹ�־", L"Ӧ�츮", L"Ӧ�츮", Point(340, 79) },
		{ L"���ǡ������Ӷ�Ա", L"�����", L"�����", Point(257, 153) },
		{ L"�����������Ӷ�Ա", L"������", L"������", Point(29, 15) },
		{ L"���֡������Ӷ�Ա", L"����С��", L"����С��", Point(43, 45) },
		{ L"��Ӧ�������Ӷ�Ա", L"Ӧ�츮", L"Ӧ�츮", Point(21, 294) },
		{ L"�����������Ӷ�Ա", L"������", L"������", Point(29, 18) },
		{ L"�ش��ţ��", L"�����", L"�����", Point(263, 158) },
		{ L"�ش�Ĺ���", L"�����", L"�����", Point(15, 172) },
		{ L"�Ի�", L"������", L"������", Point(78, 28) },
		{ L"���־�ʦ", L"������", L"������", Point(159, 115) },
		{ L"����ʦ", L"Ӧ�츮", L"Ӧ�츮", Point(31, 139) },
		{ L"����", L"�����", L"�����", Point(91, 103) },
		{ L"����嶫ɽ��", L"����嶫", L"����嶫", Point(59, 27) },
		{ L"â��ɽ´ɽ���", L"â��ɽ´", L"â��ɽ´", Point(12, 113) },
		{ L"â��ɽ´ɽ����", L"â��ɽ´", L"â��ɽ´", Point(48, 107) },
		{ L"â��ɽ´ɽ��", L"â��ɽ´", L"â��ɽ´", Point(59, 46) },
		{ L"����ͷ��", L"�����", L"�����", Point(256, 135) },
		{ L"����ͷ��", L"�����", L"�����", Point(182, 128) },
		{ L"����ͷ��", L"Ӧ�츮", L"Ӧ�츮", Point(56, 338) },
		{ L"����ͷ��", L"Ӧ�춫��", L"Ӧ�춫��", Point(69, 86) },
		{ L"����ͷ��", L"������", L"������", Point(55, 35) },
		{ L"ʥ��ͷ��", L"������", L"������", Point(63, 48) },
		{ L"����ͷ��", L"�����", L"�����", Point(76, 72) },
		{ L"����ͷ��", L"���ׯ", L"���ׯ", Point(111, 128) },
		{ L"ս��ͷ��", L"Ұ����", L"Ұ����", Point(144, 122) },
		{ L"����ͷ��", L"�꾩��", L"�꾩��", Point(357, 240) },
		{ L"ľ��ʦ��", L"Ӧ�츮", L"Ӧ�츮", Point(124, 87) },
		{ L"��������Ա", L"Ӧ�츮", L"Ӧ�츮", Point(173, 105) },
		{ L"��Ա��", L"Ӧ�츮", L"Ӧ�츮", Point(137, 198) },
		{ L"������", L"�Ҷ�����", L"�Ҷ�����", Point(23, 100) },
		{ L"������", L"���ζ���", L"���ζ���", Point(95, 46) },
		{ L"��������", L"Ӧ�츮", L"Ӧ�츮", Point(378, 83) },
		{ L"ƽ���ȷ�", L"��������", L"��������", Point(97, 45) },
		{ L"�����ȷ�", L"����", L"����", Point(65, 95) },
		{ L"�ַ��ȷ�", L"���ɽ", L"���ɽ", Point(37, 44) },
		{ L"�����ȷ�", L"�ٻ�ɽ´", L"�ٻ�ɽ´", Point(163, 77) },
		{ L"�����ȷ�", L"�ٻ�ɽ´", L"�ٻ�ɽ´", Point(14, 60) },
		{ L"����", L"��ɽ", L"��ɽ", Point(220, 130) },
		{ L"��Ӧ���̻���¼�", L"Ӧ�츮", L"Ӧ�츮", Point(88, 229) },
		{ L"��Ӧ���̻������", L"Ӧ�츮", L"Ӧ�츮", Point(177, 54) },
		{ L"���ǡ��̻����", L"�����", L"�����", Point(139, 89) },
		{ L"���꡿�̻����", L"�꾩��", L"�꾩��", Point(150, 200) },
		{ L"������", L"�����", L"�����", Point(54, 65) },
		{ L"�����", L"�����", L"�����", Point(120, 86) },
		{ L"�´�", L"�����", L"�����", Point(71, 97) },
		{ L"��̫��", L"μ�ݳ���", L"μ�ݳ���", Point(97, 90) },
		{ L"���Կ���1��", L"Ӧ�츮", L"Ӧ�츮", Point(334, 96) },
		{ L"���Կ���2��", L"Ӧ�츮", L"Ӧ�츮", Point(193, 50) },
		{ L"���Կ���3��", L"Ӧ�츮", L"Ӧ�츮", Point(59, 83) },
		{ L"���Կ���4��", L"Ӧ�츮", L"Ӧ�츮", Point(18, 165) },
		{ L"���Կ���5��", L"Ӧ�츮", L"Ӧ�츮", Point(83, 189) },
		{ L"���Կ���6��", L"Ӧ�츮", L"Ӧ�츮", Point(141, 267) },
		{ L"���Կ���7��", L"�����", L"�����", Point(180, 49) },
		{ L"���Կ���8��", L"�����", L"�����", Point(125, 96) },
		{ L"���Կ���9��", L"�����", L"�����", Point(54, 150) },
		{ L"���Կ���10��", L"�����", L"�����", Point(106, 108) },
		{ L"���Կ���11��", L"�����", L"�����", Point(193, 125) },
		{ L"���Կ���12��", L"�����", L"�����", Point(203, 75) },
		{ L"���Կ���13��", L"�����", L"�����", Point(34, 87) },
		{ L"���Կ���14��", L"�����", L"�����", Point(44, 48) },
		{ L"���Կ���15��", L"�����", L"�����", Point(126, 22) },
		{ L"���Կ���16��", L"�����", L"�����", Point(245, 29) },
		{ L"���Կ���17��", L"Ӧ�츮", L"Ӧ�츮", Point(347, 252) },
		{ L"���Կ���18��", L"Ӧ�츮", L"Ӧ�츮", Point(414, 235) },
		{ L"���Կ���19��", L"Ӧ�츮", L"Ӧ�츮", Point(456, 189) },
		{ L"���Կ���20��", L"Ӧ�츮", L"Ӧ�츮", Point(368, 152) },
		{ L"�񲿿���1��", L"�����", L"�����", Point(113, 192) },
		{ L"�񲿿���2��", L"����嶫", L"����嶫", Point(25, 13) },
		{ L"�񲿿���3��", L"â��ɽ´", L"â��ɽ´", Point(34, 144) },
		{ L"�񲿿���4��", L"�����", L"�����", Point(54, 134) },
		{ L"�񲿿���5��", L"�����", L"�����", Point(113, 127) },
		{ L"�񲿿���6��", L"�����", L"�����", Point(20, 115) },
		{ L"�񲿿���7��", L"�����", L"�����", Point(74, 11) },
		{ L"�񲿿���8��", L"Ӧ�츮", L"Ӧ�츮", Point(253, 275) },
		{ L"�񲿿���9��", L"Ӧ�츮", L"Ӧ�츮", Point(410, 275) },
		{ L"�񲿿���10��", L"Ӧ�춫��", L"Ӧ�춫��", Point(103, 81) },
		{ L"�񲿿���11��", L"��������", L"��������", Point(70, 14) },
		{ L"�񲿿���12��", L"������", L"������", Point(100, 71) },
		{ L"�񲿿���13��", L"Ӧ�츮", L"Ӧ�츮", Point(120, 171) },
		{ L"�񲿿���14��", L"Ӧ�츮", L"Ӧ�츮", Point(408, 230) },
		{ L"�񲿿���15��", L"�꾩��", L"�꾩��", Point(240, 295) },
		{ L"�񲿿���16��", L"�꾩��", L"�꾩��", Point(422, 215) },
		{ L"�񲿿���17��", L"�꾩��", L"�꾩��", Point(314, 158) },
		{ L"�񲿿���18��", L"�꾩��", L"�꾩��", Point(177, 177) },
		{ L"�񲿿���19��", L"�꾩��", L"�꾩��", Point(346, 75) },
		{ L"�񲿿���20��", L"�꾩��", L"�꾩��", Point(90, 25) },
		{ L"�ƾٱ�����Ա", L"Ӧ�츮����", L"Ӧ�츮����", Point(41, 30) },
		{ L"ˮ䰽��ƿ���", L"�꾩��", L"�꾩��", Point(102, 45) },
		{ L"�Ű���", L"�꾩��", L"�꾩��", Point(71, 13) },
		{ L"������", L"�����", L"�����", Point(196, 106) },
		{ L"��ȥ������", L"�����", L"�����", Point(215, 8) },
		{ L"Ӣ������", L"�����", L"�����", Point(65, 69) },
		{ L"��������", L"Ӧ������", L"Ӧ������", Point(145, 123) },
		{ L"��������", L"Ӧ������", L"Ӧ������", Point(72, 117) },
		{ L"Ƚ�ɴ���", L"Ӧ������", L"Ӧ������", Point(14, 38) },
		{ L"���ɹ⴫��", L"Ӧ�춫��", L"Ӧ�춫��", Point(37, 111) },
		{ L"ʷ���괫��", L"Ӧ�춫��", L"Ӧ�춫��", Point(25, 66) },
		{ L"������", L"Ӧ�춫��", L"Ӧ�춫��", Point(131, 23) },
		{ L"������", L"Ӧ�춫��", L"Ӧ�춫��", Point(31, 12) },
		{ L"�������Ա", L"���������", L"���������", Point(44, 42) },
		{ L"���ɹ���Ա", L"Ӧ�츮", L"Ӧ�츮", Point(400, 90) },
		{ L"���ɴ���Ա", L"Ӧ�츮", L"Ӧ�츮", Point(404, 92) },
		{ L"����������", L"������", L"������", Point(73, 46) },
		{ L"���������", L"�����", L"�����", Point(110, 75) },
		{ L"���ׯ����", L"���ׯ", L"���ׯ", Point(267, 138) },
		{ L"��������", L"����", L"����", Point(94, 129) },
		{ L"Ӧ�츮����", L"Ӧ�츮", L"Ӧ�츮", Point(409, 205) },
		{ L"���������", L"�����", L"�����", Point(261, 119) },
		{ L"����С������", L"����С��", L"����С��", Point(123, 63) },
		{ L"����������", L"������", L"������", Point(140, 84) },
		{ L"���ׯ����", L"���ׯ", L"���ׯ", Point(121, 99) },
		{ L"���ʪ���ز�����", L"���ʪ��", L"���ʪ��", Point(31, 36) },
		{ L"���������ز�����", L"��������", L"��������", Point(20, 25) },
		{ L"Ӧ�������ز�����", L"Ӧ������", L"Ӧ������", Point(55, 16) },
		{ L"������ز�����", L"�����", L"�����", Point(42, 107) },
		{ L"â��ɽ´�ز�����", L"â��ɽ´", L"â��ɽ´", Point(95, 68) },
		{ L"���ݵ��ز�����", L"���ݵ�", L"���ݵ�", Point(37, 190) },
		{ L"���������", L"�����", L"�����", Point(128, 145) },
		{ L"��������", L"����", L"����", Point(8, 11) },
		{ L"���ݹ���Ա", L"Ӧ�츮", L"Ӧ�츮", Point(416, 127) },
		{ L"�Ҿ��й�Ա", L"Ӧ�츮", L"Ӧ�츮", Point(408, 121) },
		{ L"���ݹ���Ա", L"�����", L"�����", Point(141, 77) },
		{ L"����Ƭ��ӢӢ", L"Ӧ�츮", L"Ӧ�츮", Point(236, 156) },
		{ L"���ǡ��ӻ�̯�ϰ�", L"�����", L"�����", Point(187, 114) },
	};

	Register(L"ResNpcPointText", &Vec);
}

VOID CResText::RegisterResShopEquiText()
{
	CONST static std::vector<ResShopEquiText> Vec = 
	{
		{ L"�鲼ͷ��", 5, 1 },
		{ L"�޲���", 5, 2 },
		{ L"�����ټ�", 5, 3 },
		{ L"���޲���", 5, 4 },
		{ L"�޲�����", 5, 5 },
		{ L"����ҽ��", 5, 6 },
		{ L"�޲���", 5, 7 },
		{ L"����", 5, 8 },
		{ L"ͭ����", 5, 9 },
		{ L"���ֻ���", 5, 10 },
		{ L"��������", 5, 11 },
		{ L"˿�ƻ���", 5, 12 },
		{ L"��ľ����", 5, 13 },
		{ L"Ӳ������", 5, 14 },
		{ L"��Ƥ����", 5, 15 },
		{ L"��Ь", 5, 16 },
		{ L"��ľЬ", 5, 17 },
		{ L"��Ь", 5, 18 },
		{ L"��ͷ��Ь", 5, 21 },
		{ L"��Ь", 5, 19 },
		{ L"��Ь", 5, 20 },
		{ L"��ѥ", 5, 22 },
		{ L"�޲�����", 5, 23 },
		{ L"�鲼����", 5, 24 },
		{ L"����ͷ��", 5, 25 },
		{ L"ѧͽ����", 5, 26 },
		{ L"��ͭս��", 5, 27 },
		{ L"���ƿ���", 5, 28 },
		{ L"����ս��", 5, 29 },
		{ L"���ĳ���", 5, 30 },
		{ L"���˳���", 5, 31 },
		{ L"���˳���", 5, 32 },
		{ L"������", 5, 33 },
		{ L"��ħ����", 5, 34 },
		{ L"��ũ��", 5, 35 },
		{ L"��������", 5, 36 },
		{ L"���Ի���", 5, 37 },
		{ L"˿�ʻ���", 5, 38 },
		{ L"ҹ�л���", 5, 39 },
		{ L"��ͷЬ", 5, 40 },
		{ L"�Ʒ�Ь", 5, 41 },
		{ L"�ĺ�ѥ", 5, 42 },
		{ L"ľ��", 5, 43 },
		{ L"��βЬ", 5, 44 },
		{ L"��Ƥѥ", 5, 45 },
		{ L"�۷�ľ��", 5, 46 },
		{ L"¹Ƥ����", 5, 47 },
		{ L"�޲�����", 5, 48 },
		{ L"��ͭ��", 1, 1 },
		{ L"������", 1, 2 },
		{ L"���콣", 1, 3 },
		{ L"���ƹŽ�", 1, 4 },
		{ L"���ƽ�", 1, 5 },
		{ L"���ǽ�", 1, 6 },
		{ L"��ľ��", 1, 7 },
		{ L"֪ʶ֮��", 1, 8 },
		{ L"�ǻ�֮��", 1, 9 },
		{ L"���֮��", 1, 10 },
		{ L"����֮��", 1, 11 },
		{ L"����֮��", 1, 12 },
		{ L"ʯ��", 1, 13 },
		{ L"ͭ��", 1, 14 },
		{ L"����", 1, 15 },
		{ L"�����", 1, 16 },
		{ L"���", 1, 32 },
		{ L"������", 1, 17 },
		{ L"������", 1, 18 },
		{ L"�鲼ȭ��", 1, 19 },
		{ L"ľ��ȭ��", 1, 20 },
		{ L"��Ƥȭ��", 1, 21 },
		{ L"�ľȭ��", 1, 22 },
		{ L"����ȭ��", 1, 23 },
		{ L"��ͭȭ��", 1, 24 },
		{ L"��ľ��«", 1, 25 },
		{ L"���Ӻ�«", 1, 26 },
		{ L"������«", 1, 27 },
		{ L"�����«", 1, 28 },
		{ L"���ƺ�«", 1, 29 },
		{ L"���̺�", 1, 30 },
		{ L"����̵�", 1, 31 },
		{ L"��ʯ", 1, 33 },
		{ L"����С��", 1, 34 },
		{ L"���", 1, 35 },
		{ L"���", 1, 36 },
		{ L"ľ��", 1, 37 },
		{ L"�̹�", 1, 38 },
		{ L"���˳���", 1, 39 },
		{ L"��ĺ��", 1, 40 },
		{ L"��ӥ��", 1, 41 },
		{ L"���鹭", 1, 42 },
		{ L"����ͷ��", 2, 1 },
		{ L"����ͷ��", 2, 2 },
		{ L"����ñ��", 2, 3 },
		{ L"ѧͽ����", 2, 4 },
		{ L"Ƥ�Ƴ���", 2, 5 },
		{ L"�����", 2, 6 },
		{ L"��ͭս��", 2, 7 },
		{ L"���Ӽ�", 2, 8 },
		{ L"��ͭ���", 2, 9 },
		{ L"���ƿ���", 2, 10 },
		{ L"��������", 2, 11 },
		{ L"��������", 2, 12 },
		{ L"����ս��", 2, 13 },
		{ L"���޷���", 2, 14 },
		{ L"�߱�����", 2, 15 },
		{ L"���ĳ���", 2, 16 },
		{ L"���ӳ���", 2, 17 },
		{ L"������", 2, 18 },
		{ L"���˳���", 2, 19 },
		{ L"������", 2, 20 },
		{ L"������", 2, 21 },
		{ L"���˳���", 2, 22 },
		{ L"����ս��", 2, 23 },
		{ L"ԧ��֯��", 2, 24 },
		{ L"��ͷЬ", 2, 25 },
		{ L"��Ƥѥ", 2, 26 },
		{ L"����ս��", 2, 27 },
		{ L"�Ʒ�Ь", 2, 28 },
		{ L"�������", 2, 29 },
		{ L"�������ѥ", 2, 30 },
		{ L"�ĺ�ѥ", 2, 31 },
		{ L"���Ь", 2, 32 },
		{ L"����ҽѥ", 2, 33 },
		{ L"ľ��", 2, 34 },
		{ L"¹Ƥѥ", 2, 35 },
		{ L"�������", 2, 36 },
		{ L"��βЬ", 2, 37 },
		{ L"����ѥ", 2, 38 },
		{ L"�������", 2, 39 },
		{ L"��Ƥѥ", 2, 40 },
		{ L"���ѥ", 2, 41 },
		{ L"�ٻ�Ь", 2, 42 },
		{ L"�۷�ľ��", 2, 43 },
		{ L"�׾�ѥ", 2, 44 },
		{ L"�ٴ�ѥ", 2, 45 },
		{ L"¹Ƥ����", 2, 46 },
		{ L"�Ͼ�����", 2, 47 },
		{ L"�������", 2, 48 },
		{ L"������", 2, 49 },
		{ L"���껤��", 2, 50 },
		{ L"θ�׻���", 2, 51 },
		{ L"��ħ����", 2, 52 },
		{ L"��������", 2, 53 },
		{ L"�Ի�������", 2, 54 },
		{ L"��ũ��", 2, 55 },
		{ L"���ֻ���", 2, 56 },
		{ L"ѩ����¶��", 2, 57 },
		{ L"��������", 2, 58 },
		{ L"��ʯ����", 2, 59 },
		{ L"�����Ͻ���", 2, 60 },
		{ L"���Ի���", 2, 61 },
		{ L"�߱�����", 2, 62 },
		{ L"��а�Ͻ���", 2, 63 },
		{ L"ҹ�л���", 2, 64 },
		{ L"��������", 2, 65 },
		{ L"��˪����", 2, 66 },
		{ L"˿�ʻ���", 2, 67 },
		{ L"��������", 2, 68 },
		{ L"��������", 2, 69 },
		{ L"������ʯ", 3, 1 },
		{ L"��а����", 3, 2 },
		{ L"�Ż����", 3, 3 },
		{ L"��������", 3, 4 },
		{ L"�ֽ�����", 3, 5 },
		{ L"�����߽�", 3, 6 },
		{ L"����������", 3, 7 },
		{ L"�������ƽ�", 3, 8 },
		{ L"��ħ��", 6, 1 },
		{ L"ʮ����", 6, 2 },
		{ L"ʲ������", 6, 3 },
		{ L"����", 6, 4 },
		{ L"������", 6, 5 },
		{ L"������", 6, 6 },
		{ L"����", 6, 7 },
		{ L"������", 6, 8 },
		{ L"����", 6, 9 },
		{ L"������", 6, 10 },
		{ L"��������", 6, 11 },
		{ L"��������", 6, 16 },
		{ L"��ؾ���", 6, 17 },
		{ L"������", 6, 18 },
		{ L"���¾���", 6, 19 },
		{ L"ħ����", 6, 22 },
		{ L"����ָ", 6, 23 },
		{ L"Сƿ������ˮ", 6, 24 },
		{ L"Сƿ���ʲ�", 6, 25 },
		{ L"Сƿ������", 6, 26 },
		{ L"С�������", 6, 27 },
		{ L"ë��", 6, 31 },
		{ L"ī", 6, 32 },
		{ L"��������", 6, 36 },
		{ L"����", 6, 37 },
		{ L"ţ��", 6, 38 },
		{ L"�̻��������̣�", 6, 39 },
		{ L"�񻨵�", 6, 40 },
		{ L"С����", 7, 1 },
		{ L"������", 7, 2 },
		{ L"ɽˮ����", 7, 3 },
		{ L"�������", 7, 4 },
		{ L"�ཷ��˿", 7, 5 },
		{ L"�Ϻõ�Ů����", 7, 6 },
		{ L"��ţ��", 7, 7 },
		{ L"ֹѪ��", 8, 1 },
		{ L"��ҩ", 8, 2 },
		{ L"������", 8, 3 },
		{ L"�����", 8, 4 },
	};

	Register(L"ResShopEquiText", &Vec);
}

VOID CResText::RegisterResShopItemText()
{
	CONST static std::vector<ResStoreItemText> Vec =
	{
		{ L"��ħ��", L"���ǡ��ӻ�̯�ϰ�",1,500 },
		{ L"ʮ����", L"���ǡ��ӻ�̯�ϰ�",2,100 },
		{ L"������", L"���ǡ��ӻ�̯�ϰ�",8,1000 },
		{ L"����峬�̷�", L"���ǡ��ӻ�̯�ϰ�",11,30000 },
		{ L"��ħ��", L"���꡿�ӻ�̯�ϰ�",1,500 },
		{ L"ʮ����", L"���꡿�ӻ�̯�ϰ�",2,100 },
		{ L"������", L"���꡿�ӻ�̯�ϰ�",8,1000 },
		{ L"�꾩�ǳ��̷�", L"���꡿�ӻ�̯�ϰ�",13,0 },
		{ L"��ħ��", L"��Ӧ���ӻ�̯�ϰ�",1,500 },
		{ L"ʮ����", L"��Ӧ���ӻ�̯�ϰ�",2,100 },
		{ L"������", L"��Ӧ���ӻ�̯�ϰ�",10,1000 },
		{ L"Ӧ�츮���̷�", L"��Ӧ���ӻ�̯�ϰ�",14,30000 },
	};
	Register(L"ResShopItemText", &Vec);
}
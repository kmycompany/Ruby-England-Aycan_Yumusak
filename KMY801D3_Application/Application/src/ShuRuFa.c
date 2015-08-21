#include "ShuRuFa.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "key.h"
#include "lcd.h"
#include "mypure_library.h"
#include "my_library.h"
#include "stm32f10x.h"
//#include "my_stdint.h"
#include "setting.h"
#include "FoodOrder.h"


typedef struct
{
	const u8 *T9;
	const u8 *PY;
	const u8 *MB;
} T9PY_IDX;

static short cursorX;
static short cursorY;


//#define AddBiHuaPinYin


#ifdef AddBiHuaPinYin
const u8 PY_mb_space [] = {"  "};
const u8 PY_mb_fuhao [] = {"���������������������������������������ã�������������������������������������������ۣݣ����֡ܡݣ����ڡۣ������£��ҡӡءޡġšơǡȡɡʡ͡ΡϡСѡա�"};
const u8 PY_mb_a     [] = {"����"};
const u8 PY_mb_ai    [] = {"��������������������������"};
const u8 PY_mb_an    [] = {"������������������"};
const u8 PY_mb_ang   [] = {"������"};
const u8 PY_mb_ao    [] = {"���������°����ð�"};
const u8 PY_mb_b     [] = {"�˰װ��"}; ////
const u8 PY_mb_ba    [] = {"�˰ѰͰְհ԰ΰǰɰӰṴ̋ưʰϰȰ�"};
const u8 PY_mb_bai   [] = {"�װٰڰܰݰ۰ذ�"};
const u8 PY_mb_ban   [] = {"�������������߰��"};
const u8 PY_mb_bang  [] = {"�������������������"};
const u8 PY_mb_bao   [] = {"������������������������������������"};
const u8 PY_mb_bei   [] = {"������������������������������"};
const u8 PY_mb_ben   [] = {"����������"};
const u8 PY_mb_beng  [] = {"�����±ñű�"};
const u8 PY_mb_bi    [] = {"�ƱǱȱ˱ʱɱұرϱձӱѱݱбֱԱͱױ̱αڱܱ�"};
const u8 PY_mb_bian  [] = {"�߱�ޱ���������"};
const u8 PY_mb_biao  [] = {"�����"};
const u8 PY_mb_bie   [] = {"�����"};
const u8 PY_mb_bin   [] = {"����������"};
const u8 PY_mb_bing  [] = {"������������������"};
const u8 PY_mb_bo    [] = {"����������������������������������������"};
const u8 PY_mb_bu    [] = {"��������������������"};
const u8 PY_mb_c     [] = {"���²β�"}; ///
const u8 PY_mb_ca    [] = {"��"};
const u8 PY_mb_cai   [] = {"�²ŲĲƲòɲʲǲȲ˲�"};
const u8 PY_mb_can   [] = {"�βͲвϲѲҲ�"};
const u8 PY_mb_cang  [] = {"�ֲײԲղ�"};
const u8 PY_mb_cao   [] = {"�ٲڲܲ۲�"};
const u8 PY_mb_ce    [] = {"���޲��"};
const u8 PY_mb_ceng  [] = {"�����"};
const u8 PY_mb_cha   [] = {"������������ɲ"};
const u8 PY_mb_chai  [] = {"����"};
const u8 PY_mb_chan  [] = {"�������������������"};
const u8 PY_mb_chang [] = {"������������������������"};
const u8 PY_mb_chao  [] = {"��������������������"};
const u8 PY_mb_che   [] = {"������������"};
const u8 PY_mb_chen  [] = {"�������������³��ĳ�"};
const u8 PY_mb_cheng [] = {"�Ƴųɳʳгϳǳ˳ͳ̳γȳѳҳ�"};
const u8 PY_mb_chi   [] = {"�Գճڳس۳ٳֳ߳޳ݳܳ����"};
const u8 PY_mb_chong [] = {"������"};
const u8 PY_mb_chou  [] = {"�������������"};
const u8 PY_mb_chu   [] = {"����������������������������������"};
const u8 PY_mb_chuai [] = {"��"};
const u8 PY_mb_chuan [] = {"��������������"};
const u8 PY_mb_chuang[] = {"����������"};
const u8 PY_mb_chui  [] = {"����������"};
const u8 PY_mb_chun  [] = {"��������������"};
const u8 PY_mb_chuo  [] = {"��"};
const u8 PY_mb_ci    [] = {"�ôʴĴɴȴǴŴƴ˴δ̴�"};
const u8 PY_mb_cong  [] = {"�ѴӴҴдϴ�"};
const u8 PY_mb_cou   [] = {"��"};
const u8 PY_mb_cu    [] = {"�ִٴ״�"};
const u8 PY_mb_cuan  [] = {"�ڴܴ�"};
const u8 PY_mb_cui   [] = {"�޴ߴݴ�����"};
const u8 PY_mb_cun   [] = {"����"};
const u8 PY_mb_cuo   [] = {"�������"};
const u8 PY_mb_d     [] = {"�������"}; ///
const u8 PY_mb_da    [] = {"�������"};
const u8 PY_mb_dai   [] = {"������������������������"};
const u8 PY_mb_dan   [] = {"������������������������������"};
const u8 PY_mb_dang  [] = {"����������"};
const u8 PY_mb_dao   [] = {"������������������������"};
const u8 PY_mb_de    [] = {"�õµ�"};
const u8 PY_mb_deng  [] = {"�Ƶǵŵȵ˵ʵ�"};
const u8 PY_mb_di    [] = {"�͵̵εҵϵеӵѵյ׵ֵصܵ۵ݵڵ޵�"};
const u8 PY_mb_dian  [] = {"���ߵ�������������"};
const u8 PY_mb_diao  [] = {"�����������"};
const u8 PY_mb_die   [] = {"��������������"};
const u8 PY_mb_ding  [] = {"������������������"};
const u8 PY_mb_diu   [] = {"��"};
const u8 PY_mb_dong  [] = {"��������������������"};
const u8 PY_mb_dou   [] = {"����������������"};
const u8 PY_mb_du    [] = {"�����������¶ĶöʶŶǶȶɶ�"};
const u8 PY_mb_duan  [] = {"�˶̶ζ϶ж�"};
const u8 PY_mb_dui   [] = {"�ѶӶԶ�"};
const u8 PY_mb_dun   [] = {"�ֶضն׶ܶ۶ٶ�"};
const u8 PY_mb_duo   [] = {"��߶�޶��������"};
const u8 PY_mb_e     [] = {"����������������"};
const u8 PY_mb_en    [] = {"��"};
const u8 PY_mb_er    [] = {"����������������"};
const u8 PY_mb_f     [] = {"�������ɷ�"}; ///
const u8 PY_mb_fa    [] = {"����������������"};
const u8 PY_mb_fan   [] = {"����������������������������������"};
const u8 PY_mb_fang  [] = {"���������������·÷ķ�"};
const u8 PY_mb_fei   [] = {"�ɷǷȷƷʷ˷̷ͷϷзη�"};
const u8 PY_mb_fen   [] = {"�ַԷ׷ҷշӷطڷٷ۷ݷܷ޷߷�"};
const u8 PY_mb_feng  [] = {"����������������"};
const u8 PY_mb_fo    [] = {"��"};
const u8 PY_mb_fou   [] = {"��"};
const u8 PY_mb_fu    [] = {"������󸥷�����������������������������������������������������������������������������"};
const u8 PY_mb_g     [] = {"�¸øɸԸ�"}; ///
const u8 PY_mb_ga    [] = {"�¸�"};
const u8 PY_mb_gai   [] = {"�øĸƸǸȸ�"};
const u8 PY_mb_gan   [] = {"�ɸʸ˸θ̸͸ѸϸҸи�"};
const u8 PY_mb_gang  [] = {"�Ըոڸٸظ׸ָ۸�"};
const u8 PY_mb_gao   [] = {"�޸�߸�ݸ�����"};
const u8 PY_mb_ge    [] = {"����������������������"};
const u8 PY_mb_gei   [] = {"��"};
const u8 PY_mb_gen   [] = {"����"};
const u8 PY_mb_geng  [] = {"��������������"};
const u8 PY_mb_gong  [] = {"������������������������������"};
const u8 PY_mb_gou   [] = {"������������������"};
const u8 PY_mb_gu    [] = {"�����ù¹��������ŹȹɹǹƹĹ̹ʹ˹�"};
const u8 PY_mb_gua   [] = {"�Ϲιйѹҹ�"};
const u8 PY_mb_guai  [] = {"�Թչ�"};
const u8 PY_mb_guan  [] = {"�ع۹ٹڹ׹ݹܹ�߹��"};
const u8 PY_mb_guang [] = {"����"};
const u8 PY_mb_gui   [] = {"������������������"};
const u8 PY_mb_gun   [] = {"������"};
const u8 PY_mb_guo   [] = {"������������"};
const u8 PY_mb_h     [] = {"�򺢺�����"}; ///
const u8 PY_mb_ha    [] = {"���"};
const u8 PY_mb_hai   [] = {"��������������"};
const u8 PY_mb_han   [] = {"��������������������������������������"};
const u8 PY_mb_hang  [] = {"������"};
const u8 PY_mb_hao   [] = {"���������úºźƺ�"};
const u8 PY_mb_he    [] = {"�ǺȺ̺ϺκͺӺҺ˺ɺԺкʺغֺպ�"};
const u8 PY_mb_hei   [] = {"�ں�"};
const u8 PY_mb_hen   [] = {"�ۺܺݺ�"};
const u8 PY_mb_heng  [] = {"��ߺ���"};
const u8 PY_mb_hong  [] = {"����������"};
const u8 PY_mb_hou   [] = {"��������"};
const u8 PY_mb_hu    [] = {"������������������������������������"};
const u8 PY_mb_hua   [] = {"������������������"};
const u8 PY_mb_huai  [] = {"����������"};
const u8 PY_mb_huan  [] = {"�����������û»�������������"};
const u8 PY_mb_huang [] = {"�ĻŻʻ˻ƻ̻ͻȻǻɻлλѻ�"};
const u8 PY_mb_hui   [] = {"�һֻӻԻջػ׻ڻܻ������߻޻�ݻٻ�"};
const u8 PY_mb_hun   [] = {"�������"};
const u8 PY_mb_huo   [] = {"�������������"};
const u8 PY_mb_j     [] = {"���Ӽ齭��"}; ///
const u8 PY_mb_ji    [] = {"���������������������������������������������������������������������ƼǼ��ͼ˼ɼ��ʼ����ȼü̼żļ¼�������"};
const u8 PY_mb_jia   [] = {"�ӼмѼϼҼμԼռ׼ּؼۼݼܼټ޼�Ю"};
const u8 PY_mb_jian  [] = {"����߼����������������������������������������������������"};
const u8 PY_mb_jiang [] = {"��������������������������"};
const u8 PY_mb_jiao  [] = {"���������������������ǽƽʽȽýŽ½��˽ɽнνϽ̽ѽ;���"};
const u8 PY_mb_jie   [] = {"�׽Խӽսҽֽڽٽܽ��ݽ޽ؽ߽����������"};
const u8 PY_mb_jin   [] = {"���������������������������������"};
const u8 PY_mb_jing  [] = {"��������������������������������������������������"};
const u8 PY_mb_jiong [] = {"����"};
const u8 PY_mb_jiu   [] = {"�������žþľ��¾ƾɾʾ̾ξǾȾ;�"};
const u8 PY_mb_ju    [] = {"�ӾоѾԾҾϾֽ۾վ׾ھپؾ�޾ܾ߾����ݾ��۾�"};
const u8 PY_mb_juan  [] = {"��������"};
const u8 PY_mb_jue   [] = {"��������������"};
const u8 PY_mb_jun   [] = {"����������������������"};
const u8 PY_mb_k     [] = {"����������"}; ///
const u8 PY_mb_ka    [] = {"������"};
const u8 PY_mb_kai   [] = {"����������"};
const u8 PY_mb_kan   [] = {"��������������"};
const u8 PY_mb_kang  [] = {"��������������"};
const u8 PY_mb_kao   [] = {"��������"};
const u8 PY_mb_ke    [] = {"�����¿ƿÿſĿǿȿɿʿ˿̿Ϳ�"};
const u8 PY_mb_ken   [] = {"�Ͽѿҿ�"};
const u8 PY_mb_keng  [] = {"�Կ�"};
const u8 PY_mb_kong  [] = {"�տ׿ֿ�"};
const u8 PY_mb_kou   [] = {"�ٿڿۿ�"};
const u8 PY_mb_ku    [] = {"�ݿ޿߿����"};
const u8 PY_mb_kua   [] = {"������"};
const u8 PY_mb_kuai  [] = {"�����"};
const u8 PY_mb_kuan  [] = {"���"};
const u8 PY_mb_kuang [] = {"�����������"};
const u8 PY_mb_kui   [] = {"����������������������"};
const u8 PY_mb_kun   [] = {"��������"};
const u8 PY_mb_kuo   [] = {"��������"};
const u8 PY_mb_l     [] = {"����������"}; ///
const u8 PY_mb_la    [] = {"��������������"};
const u8 PY_mb_lai   [] = {"������"};
const u8 PY_mb_lan   [] = {"������������������������������"};
const u8 PY_mb_lang  [] = {"��������������"};
const u8 PY_mb_lao   [] = {"������������������"};
const u8 PY_mb_le    [] = {"������"};
const u8 PY_mb_lei   [] = {"����������������������"};
const u8 PY_mb_leng  [] = {"������"};
const u8 PY_mb_li    [] = {"��������������������������������������������������������������������"};
const u8 PY_mb_lian  [] = {"����������������������������"};
const u8 PY_mb_liang [] = {"������������������������"};
const u8 PY_mb_liao  [] = {"������������������������"};
const u8 PY_mb_lie   [] = {"����������"};
const u8 PY_mb_lin   [] = {"������������������������"};
const u8 PY_mb_ling  [] = {"����������������������������"};
const u8 PY_mb_liu   [] = {"����������������������"};
const u8 PY_mb_long  [] = {"��������¡��¤¢£"};
const u8 PY_mb_lou   [] = {"¦¥§¨ª©"};
const u8 PY_mb_lu    [] = {"¶¬®«¯­±²°³½¼¸¹»µ·¾º´"};
const u8 PY_mb_luan  [] = {"������������"};
const u8 PY_mb_lue   [] = {"����"};
const u8 PY_mb_lun   [] = {"��������������"};
const u8 PY_mb_luo   [] = {"������������������������"};
const u8 PY_mb_lv    [] = {"��¿������������������������"};
const u8 PY_mb_m     [] = {"������æè"}; ///
const u8 PY_mb_ma    [] = {"������������������"};
const u8 PY_mb_mai   [] = {"������������"};
const u8 PY_mb_man   [] = {"����������á������"};
const u8 PY_mb_mang  [] = {"æâäãçå"};
const u8 PY_mb_mao   [] = {"èëìéêîíïðóñò"};
const u8 PY_mb_me    [] = {"ô"};
const u8 PY_mb_mei   [] = {"ûöõü÷ýúøùÿ��þ��������"};
const u8 PY_mb_men   [] = {"������"};
const u8 PY_mb_meng  [] = {"����������������"};
const u8 PY_mb_mi    [] = {"����������������������������"};
const u8 PY_mb_mian  [] = {"������������������"};
const u8 PY_mb_miao  [] = {"����������������"};
const u8 PY_mb_mie   [] = {"����"};
const u8 PY_mb_min   [] = {"������������"};
const u8 PY_mb_ming  [] = {"������������"};
const u8 PY_mb_miu   [] = {"��"};
const u8 PY_mb_mo    [] = {"����ġģĤĦĥĢħĨĩĭİĪįĮīĬ"};
const u8 PY_mb_mou   [] = {"Ĳıĳ"};
const u8 PY_mb_mu    [] = {"ĸĶĵķĴľĿ��ļĹĻ��Ľĺ��"};
const u8 PY_mb_n     [] = {"������"}; ///
const u8 PY_mb_na    [] = {"��������������"};
const u8 PY_mb_nai   [] = {"����������"};
const u8 PY_mb_nan   [] = {"�������"};
const u8 PY_mb_nang  [] = {"��"};
const u8 PY_mb_nao   [] = {"����������"};
const u8 PY_mb_ne    [] = {"��"};
const u8 PY_mb_nei   [] = {"����"};
const u8 PY_mb_nen   [] = {"��"};
const u8 PY_mb_neng  [] = {"��"};
const u8 PY_mb_ni    [] = {"����������������������"};
const u8 PY_mb_nian  [] = {"��������������"};
const u8 PY_mb_niang [] = {"����"};
const u8 PY_mb_niao  [] = {"����"};
const u8 PY_mb_nie   [] = {"��������������"};
const u8 PY_mb_nin   [] = {"��"};
const u8 PY_mb_ning  [] = {"��š������Ţ"};
const u8 PY_mb_niu   [] = {"ţŤŦť"};
const u8 PY_mb_nong  [] = {"ũŨŧŪ"};
const u8 PY_mb_nu    [] = {"ūŬŭ"};
const u8 PY_mb_nuan  [] = {"ů"};
const u8 PY_mb_nue   [] = {"űŰ"};
const u8 PY_mb_nuo   [] = {"ŲŵųŴ"};
const u8 PY_mb_nv    [] = {"Ů"};
const u8 PY_mb_o     [] = {"Ŷ"};
const u8 PY_mb_ou    [] = {"ŷŹŸŻżźŽ"};
const u8 PY_mb_p     [] = {"ſ������"}; ///
const u8 PY_mb_pa    [] = {"ſž����������"};
const u8 PY_mb_pai   [] = {"������������"};
const u8 PY_mb_pan   [] = {"����������������"};
const u8 PY_mb_pang  [] = {"����������"};
const u8 PY_mb_pao   [] = {"��������������"};
const u8 PY_mb_pei   [] = {"������������������"};
const u8 PY_mb_pen   [] = {"����"};
const u8 PY_mb_peng  [] = {"����������������������������"};
const u8 PY_mb_pi    [] = {"��������������Ƥ��ƣơ��ƢƥƦƨƧƩ"};
const u8 PY_mb_pian  [] = {"Ƭƫƪƭ"};
const u8 PY_mb_piao  [] = {"ƯƮưƱ"};
const u8 PY_mb_pie   [] = {"ƲƳ"};
const u8 PY_mb_pin   [] = {"ƴƶƵƷƸ"};
const u8 PY_mb_ping  [] = {"ƽ��ƾ��ƿƺƻƼƹ"};
const u8 PY_mb_po    [] = {"����������������"};
const u8 PY_mb_pou   [] = {"��"};
const u8 PY_mb_pu    [] = {"������������������������������"};
const u8 PY_mb_q     [] = {"����ǧǺ"}; ///
const u8 PY_mb_qi    [] = {"������������������������������������������������������������������������"};
const u8 PY_mb_qia   [] = {"��ǡǢ"};
const u8 PY_mb_qian  [] = {"ǧǪǤǨǥǣǦǫǩǰǮǯǬǱǭǳǲǴǷǵǶǸ"};
const u8 PY_mb_qiang [] = {"ǺǼǹǻǿǽǾ��"};
const u8 PY_mb_qiao  [] = {"������������������������������"};
const u8 PY_mb_qie   [] = {"����������"};
const u8 PY_mb_qin   [] = {"����������������������"};
const u8 PY_mb_qing  [] = {"��������������������������"};
const u8 PY_mb_qiong [] = {"����"};
const u8 PY_mb_qiu   [] = {"����������������"};
const u8 PY_mb_qu    [] = {"����������������ȡȢȣȥȤ"};
const u8 PY_mb_quan  [] = {"ȦȫȨȪȭȬȩȧȮȰȯ"};
const u8 PY_mb_que   [] = {"Ȳȱȳȴȸȷȵȶ"};
const u8 PY_mb_qun   [] = {"ȹȺ"};
const u8 PY_mb_r     [] = {"Ȼȿ��"}; ///
const u8 PY_mb_ran   [] = {"ȻȼȽȾ"};
const u8 PY_mb_rang  [] = {"ȿ��������"};
const u8 PY_mb_rao   [] = {"������"};
const u8 PY_mb_re    [] = {"����"};
const u8 PY_mb_ren   [] = {"��������������������"};
const u8 PY_mb_reng  [] = {"����"};
const u8 PY_mb_ri    [] = {"��"};
const u8 PY_mb_rong  [] = {"��������������������"};
const u8 PY_mb_rou   [] = {"������"};
const u8 PY_mb_ru    [] = {"��������������������"};
const u8 PY_mb_ruan  [] = {"����"};
const u8 PY_mb_rui   [] = {"������"};
const u8 PY_mb_run   [] = {"����"};
const u8 PY_mb_ruo   [] = {"����"};
const u8 PY_mb_s     [] = {"������"}; ///
const u8 PY_mb_sa    [] = {"������"};
const u8 PY_mb_sai   [] = {"��������"};
const u8 PY_mb_san   [] = {"��ɡɢ��"};
const u8 PY_mb_sang  [] = {"ɣɤɥ"};
const u8 PY_mb_sao   [] = {"ɦɧɨɩ"};
const u8 PY_mb_se    [] = {"ɫɬɪ"};
const u8 PY_mb_sen   [] = {"ɭ"};
const u8 PY_mb_seng  [] = {"ɮ"};
const u8 PY_mb_sha   [] = {"ɱɳɴɰɯɵɶɷ��"};
const u8 PY_mb_shai  [] = {"ɸɹ"};
const u8 PY_mb_shan  [] = {"ɽɾɼ��ɺɿ������ɻ������������դ"};
const u8 PY_mb_shang [] = {"����������������"};
const u8 PY_mb_shao  [] = {"����������������������"};
const u8 PY_mb_she   [] = {"������������������������"};
const u8 PY_mb_shen  [] = {"��������������������������������ʲ"};
const u8 PY_mb_sheng [] = {"��������ʤ����ʡʥʢʣ"};
const u8 PY_mb_shi   [] = {"��ʮʯʱʿʶ��ʳʾʽʹʼ����ʵ����ʷ��ʩ��ʻʪ�Ƴ�ʬʧ����ʦʭʫʨʰʴʸʺ����������������������"};
const u8 PY_mb_shou  [] = {"��������������������"};
const u8 PY_mb_shu   [] = {"������������������������������������������������������ˡ����������"};
const u8 PY_mb_shua  [] = {"ˢˣ"};
const u8 PY_mb_shuai [] = {"˥ˤ˦˧"};
const u8 PY_mb_shuan [] = {"˩˨"};
const u8 PY_mb_shuang[] = {"˫˪ˬ"};
const u8 PY_mb_shui  [] = {"˭ˮ˰˯"};
const u8 PY_mb_shun  [] = {"˱˳˴˲"};
const u8 PY_mb_shuo  [] = {"˵˸˷˶"};
const u8 PY_mb_si    [] = {"��˿˾˽˼˹��˺��˻����������"};
const u8 PY_mb_song  [] = {"����������������"};
const u8 PY_mb_sou   [] = {"��������"};
const u8 PY_mb_su    [] = {"����������������������"};
const u8 PY_mb_suan  [] = {"������"};
const u8 PY_mb_sui   [] = {"����������������������"};
const u8 PY_mb_sun   [] = {"������"};
const u8 PY_mb_suo   [] = {"����������������"};
const u8 PY_mb_t     [] = {"��̥̮��"}; ///
const u8 PY_mb_ta    [] = {"����������̡̢̤̣"};
const u8 PY_mb_tai   [] = {"̨̧̥̦̫̭̬̩̪"};
const u8 PY_mb_tan   [] = {"̸̵̷̶̴̮̰̯̲̱̳̹̻̺̼̾̿̽"};
const u8 PY_mb_tang  [] = {"��������������������������"};
const u8 PY_mb_tao   [] = {"����������������������"};
const u8 PY_mb_te    [] = {"��"};
const u8 PY_mb_teng  [] = {"��������"};
const u8 PY_mb_ti    [] = {"������������������������������"};
const u8 PY_mb_tian  [] = {"����������������"};
const u8 PY_mb_tiao  [] = {"������������"};
const u8 PY_mb_tie   [] = {"������"};
const u8 PY_mb_ting  [] = {"ͣ��͡����ͤͥͦͧ͢"};
const u8 PY_mb_tong  [] = {"ͨͬͮͩͭͯͪͫͳͱͰͲʹ"};
const u8 PY_mb_tou   [] = {"͵ͷͶ͸"};
const u8 PY_mb_tu    [] = {"͹ͺͻͼͽͿ;��������"};
const u8 PY_mb_tuan  [] = {"����"};
const u8 PY_mb_tui   [] = {"������������"};
const u8 PY_mb_tun   [] = {"��������"};
const u8 PY_mb_tuo   [] = {"����������������������"};
const u8 PY_mb_w     [] = {"��������Σ"}; ///
const u8 PY_mb_wa    [] = {"��������������"};
const u8 PY_mb_wai   [] = {"����"};
const u8 PY_mb_wan   [] = {"����������������������������������"};
const u8 PY_mb_wang  [] = {"��������������������"};
const u8 PY_mb_wei   [] = {"Σ��΢ΡΪΤΧΥΦΨΩάΫΰαβγέίή��δλζηθξνιμεοκ"};
const u8 PY_mb_wen   [] = {"��������������������"};
const u8 PY_mb_weng  [] = {"������"};
const u8 PY_mb_wo    [] = {"������������������"};
const u8 PY_mb_wu    [] = {"����������������������������������������������������������"};
const u8 PY_mb_x     [] = {"ϦϺϳ��"}; ///
const u8 PY_mb_xi    [] = {"Ϧϫ����ϣ������Ϣ��Ϥϧϩ����ϬϡϪ��Ϩ����ϥϰϯϮϱϭϴϲϷϵϸ϶"};
const u8 PY_mb_xia   [] = {"ϺϹϻ��Ͽ��ϾϽϼ������"};
const u8 PY_mb_xian  [] = {"ϳ����������������������������������������������������"};
const u8 PY_mb_xiang [] = {"����������������������������������������"};
const u8 PY_mb_xiao  [] = {"����������������С��ТФ��ЧУЦХ"};
const u8 PY_mb_xie   [] = {"ЩШЪЫЭавбгЯЬдйкжмелиз"};
const u8 PY_mb_xin   [] = {"����о����п��н����"};
const u8 PY_mb_xing  [] = {"����������������������������"};
const u8 PY_mb_xiong [] = {"��������������"};
const u8 PY_mb_xiu   [] = {"��������������������"};
const u8 PY_mb_xu    [] = {"��������������������������������������"};
const u8 PY_mb_xuan  [] = {"������������ѡѢѤѣ"};
const u8 PY_mb_xue   [] = {"ѧѩѪ��ѥѦѨ"};
const u8 PY_mb_xun   [] = {"ѰѮѸѯѶѫѬѲѱѭѵѴѷѳ"};
const u8 PY_mb_y     [] = {"ѽ������Ҭ"}; ///
const u8 PY_mb_ya    [] = {"ѽѹ������ѾѺѻѼѿ������������"};
const u8 PY_mb_yan   [] = {"������������������������������������������������������������������"};
const u8 PY_mb_yang  [] = {"����������������������������������"};
const u8 PY_mb_yao   [] = {"��������ҢҦҤҥҡң��ҧҨҩҪҫԿ"};
const u8 PY_mb_ye    [] = {"ҬҭүҮҲұҰҵҶҷҳҹҴҺҸ"};
const u8 PY_mb_yi    [] = {"һ����ҽ��ҿҼҾ������������������������������������������������������������������������������������������"};
const u8 PY_mb_yin   [] = {"������������������������������ӡ"};
const u8 PY_mb_ying  [] = {"ӦӢӤӧӣӥӭӯӫӨөӪӬӮӱӰӳӲ"};
const u8 PY_mb_yo    [] = {"Ӵ"};
const u8 PY_mb_yong  [] = {"ӶӵӸӹӺӷ��ӽӾ��ӿ��Ӽӻ��"};
const u8 PY_mb_you   [] = {"����������������������������������������"};
const u8 PY_mb_yu    [] = {"����������������������������������������������������Ԧ����������ԡԤ������Ԣ��ԣ������ԥ"};
const u8 PY_mb_yuan  [] = {"ԩԧԨԪԱ԰ԫԭԲԬԮԵԴԳԯԶԷԹԺԸ"};
const u8 PY_mb_yue   [] = {"ԻԼ��������Ծ��Խ"};
const u8 PY_mb_yun   [] = {"������������������������"};
const u8 PY_mb_z     [] = {"������"}; ///
const u8 PY_mb_za    [] = {"������զ"};
const u8 PY_mb_zai   [] = {"����������������"};
const u8 PY_mb_zan   [] = {"��������"};
const u8 PY_mb_zang  [] = {"������"};
const u8 PY_mb_zao   [] = {"����������������������������"};
const u8 PY_mb_ze    [] = {"��������"};
const u8 PY_mb_zei   [] = {"��"};
const u8 PY_mb_zen   [] = {"��"};
const u8 PY_mb_zeng  [] = {"������"};
const u8 PY_mb_zha   [] = {"����������բագէթըե��"};
const u8 PY_mb_zhai  [] = {"իժլ��խծկ"};
const u8 PY_mb_zhan  [] = {"մձճղհնչյոշռսջվ��տպ"};
const u8 PY_mb_zhang [] = {"��������������������������������"};
const u8 PY_mb_zhao  [] = {"��������������������צ"};
const u8 PY_mb_zhe   [] = {"����������������������"};
const u8 PY_mb_zhen  [] = {"��������������������������������֡"};
const u8 PY_mb_zheng [] = {"��������������������֤֣��֢"};
const u8 PY_mb_zhi   [] = {"ְֱֲֳִֵֶַָֹֺֻּֽ֧֥֦֪֭֮֨֯֫֬֩��־������������ֿ������������������"};
const u8 PY_mb_zhong [] = {"����������������������"};
const u8 PY_mb_zhou  [] = {"����������������������������"};
const u8 PY_mb_zhu   [] = {"��סעף������������������������������������פ������"};
const u8 PY_mb_zhua  [] = {"ץ"};
const u8 PY_mb_zhuai [] = {"ק"};
const u8 PY_mb_zhuan [] = {"רשת׫׭"};
const u8 PY_mb_zhuang[] = {"ױׯ׮װ׳״��ײ"};
const u8 PY_mb_zhui  [] = {"׷׹׵׶׺׸"};
const u8 PY_mb_zhun  [] = {"׼׻"};
const u8 PY_mb_zhuo  [] = {"׿׾׽��������������"};
const u8 PY_mb_zi    [] = {"����������������������������"};
const u8 PY_mb_zong  [] = {"��������������"};
const u8 PY_mb_zou   [] = {"��������"};
const u8 PY_mb_zu    [] = {"����������������"};
const u8 PY_mb_zuan  [] = {"׬����"};
const u8 PY_mb_zui   [] = {"��������"};
const u8 PY_mb_zun   [] = {"����"};
const u8 PY_mb_zuo   [] = {"��������������"};





const T9PY_IDX Nult9py;
const T9PY_IDX t9PY_index[] =
{
	{"0", "0", PY_mb_space},
	{"*", "symbol", PY_mb_fuhao},	//ding add
	//{"2","A",PY_mb_a},
	{"2", "a", PY_mb_a},
	//{"2","B",PY_mb_space},
	{"2", "b", PY_mb_b},
	//{"2","C",PY_mb_space},
	{"2", "c", PY_mb_c},
	//{"3","D",PY_mb_space},
	{"3", "d", PY_mb_d},
	//{"3","E",PY_mb_e},
	{"3", "e", PY_mb_e},
	//{"3","F",PY_mb_space},
	{"3", "f", PY_mb_f},
	//{"4","G",PY_mb_space},
	{"4", "g", PY_mb_g},
	//{"4","H",PY_mb_space},
	{"4", "h", PY_mb_h},
	//{"4","I",PY_mb_space},
	//{"4","i",PY_mb_space},
	//{"5","J",PY_mb_space},
	{"5", "j", PY_mb_j},
	//{"5","K",PY_mb_space},
	{"5", "k", PY_mb_k},
	//{"5","L",PY_mb_space},
	{"5", "l", PY_mb_l},
	//{"6","M",PY_mb_space},
	{"6", "m", PY_mb_m},
	//{"6","N",PY_mb_space},
	{"6", "n", PY_mb_n},
	//{"6","O",PY_mb_o},
	{"6", "o", PY_mb_o},
	//{"7","P",PY_mb_space},
	{"7", "p", PY_mb_p},
	//{"7","Q",PY_mb_space},
	{"7", "q", PY_mb_q},
	//{"7","R",PY_mb_space},
	{"7", "r", PY_mb_r},
	//{"7","S",PY_mb_space},
	{"7", "s", PY_mb_s},
	//{"8","T",PY_mb_space},
	{"8", "t", PY_mb_t},
	//{"8","U",PY_mb_space},
	//{"8","u",PY_mb_space},
	//{"8","V",PY_mb_space},
	//{"8","v",PY_mb_space},
	//{"9","W",PY_mb_space},
	{"9", "w", PY_mb_w},
	//{"9","X",PY_mb_space},
	{"9", "x", PY_mb_x},
	//{"9","Y",PY_mb_space},
	{"9", "y", PY_mb_y},
	//{"9","Z",PY_mb_space},
	{"9", "z", PY_mb_z},
	{"24", "ai", PY_mb_ai},
	{"26", "an", PY_mb_an},
	{"26", "ao", PY_mb_ao},
	{"22", "ba", PY_mb_ba},
	{"24", "bi", PY_mb_bi},
	{"26", "bo", PY_mb_bo},
	{"28", "bu", PY_mb_bu},
	{"22", "ca", PY_mb_ca},
	{"23", "ce", PY_mb_ce},
	{"24", "ci", PY_mb_ci},
	{"28", "cu", PY_mb_cu},
	{"32", "da", PY_mb_da},
	{"33", "de", PY_mb_de},
	{"34", "di", PY_mb_di},
	{"38", "du", PY_mb_du},
	{"36", "en", PY_mb_en},
	{"37", "er", PY_mb_er},
	{"32", "fa", PY_mb_fa},
	{"36", "fo", PY_mb_fo},
	{"38", "fu", PY_mb_fu},
	{"42", "ha", PY_mb_ha},
	{"42", "ga", PY_mb_ga},
	{"43", "ge", PY_mb_ge},
	{"43", "he", PY_mb_he},
	{"48", "gu", PY_mb_gu},
	{"48", "hu", PY_mb_hu},
	{"54", "ji", PY_mb_ji},
	{"58", "ju", PY_mb_ju},
	{"52", "ka", PY_mb_ka},
	{"53", "ke", PY_mb_ke},
	{"58", "ku", PY_mb_ku},
	{"52", "la", PY_mb_la},
	{"53", "le", PY_mb_le},
	{"54", "li", PY_mb_li},
	{"58", "lu", PY_mb_lu},
	{"58", "lv", PY_mb_lv},
	{"62", "ma", PY_mb_ma},
	{"63", "me", PY_mb_me},
	{"64", "mi", PY_mb_mi},
	{"66", "mo", PY_mb_mo},
	{"68", "mu", PY_mb_mu},
	{"62", "na", PY_mb_na},
	{"63", "ne", PY_mb_ne},
	{"64", "ni", PY_mb_ni},
	{"68", "nu", PY_mb_nu},
	{"68", "nv", PY_mb_nv},
	{"68", "ou", PY_mb_ou},
	{"72", "pa", PY_mb_pa},
	{"74", "pi", PY_mb_pi},
	{"76", "po", PY_mb_po},
	{"78", "pu", PY_mb_pu},
	{"74", "qi", PY_mb_qi},
	{"78", "qu", PY_mb_qu},
	{"73", "re", PY_mb_re},
	{"74", "ri", PY_mb_ri},
	{"78", "ru", PY_mb_ru},
	{"72", "sa", PY_mb_sa},
	{"73", "se", PY_mb_se},
	{"74", "si", PY_mb_si},
	{"78", "su", PY_mb_su},
	{"82", "ta", PY_mb_ta},
	{"83", "te", PY_mb_te},
	{"84", "ti", PY_mb_ti},
	{"88", "tu", PY_mb_tu},
	{"92", "wa", PY_mb_wa},
	{"96", "wo", PY_mb_wo},
	{"98", "wu", PY_mb_wu},
	{"94", "xi", PY_mb_xi},
	{"98", "xu", PY_mb_xu},
	{"92", "ya", PY_mb_ya},
	{"93", "ye", PY_mb_ye},
	{"94", "yi", PY_mb_yi},
	{"96", "yo", PY_mb_yo},
	{"98", "yu", PY_mb_yu},
	{"92", "za", PY_mb_za},
	{"93", "ze", PY_mb_ze},
	{"94", "zi", PY_mb_zi},
	{"98", "zu", PY_mb_zu},
	{"264", "ang", PY_mb_ang},
	{"224", "bai", PY_mb_bai},
	{"226", "ban", PY_mb_ban},
	{"226", "bao", PY_mb_bao},
	{"234", "bei", PY_mb_bei},
	{"236", "ben", PY_mb_ben},
	{"243", "bie", PY_mb_bie},
	{"246", "bin", PY_mb_bin},
	{"224", "cai", PY_mb_cai},
	{"226", "can", PY_mb_can},
	{"226", "cao", PY_mb_cao},
	{"242", "cha", PY_mb_cha},
	{"243", "che", PY_mb_che},
	{"244", "chi", PY_mb_chi},
	{"248", "chu", PY_mb_chu},
	{"268", "cou", PY_mb_cou},
	{"284", "cui", PY_mb_cui},
	{"286", "cun", PY_mb_cun},
	{"286", "cuo", PY_mb_cuo},
	{"324", "dai", PY_mb_dai},
	{"326", "dan", PY_mb_dan},
	{"326", "dao", PY_mb_dao},
	{"343", "die", PY_mb_die},
	{"348", "diu", PY_mb_diu},
	{"368", "dou", PY_mb_dou},
	{"384", "dui", PY_mb_dui},
	{"386", "dun", PY_mb_dun},
	{"386", "duo", PY_mb_duo},
	{"326", "fan", PY_mb_fan},
	{"334", "fei", PY_mb_fei},
	{"336", "fen", PY_mb_fen},
	{"368", "fou", PY_mb_fou},
	{"424", "gai", PY_mb_gai},
	{"426", "gan", PY_mb_gan},
	{"426", "gao", PY_mb_gao},
	{"434", "gei", PY_mb_gei},
	{"436", "gen", PY_mb_gan},
	{"468", "gou", PY_mb_gou},
	{"482", "gua", PY_mb_gua},
	{"484", "gui", PY_mb_gui},
	{"486", "gun", PY_mb_gun},
	{"486", "guo", PY_mb_guo},
	{"424", "hai", PY_mb_hai},
	{"426", "han", PY_mb_han},
	{"426", "hao", PY_mb_hao},
	{"434", "hei", PY_mb_hei},
	{"436", "hen", PY_mb_hen},
	{"468", "hou", PY_mb_hou},
	{"482", "hua", PY_mb_hua},
	{"484", "hui", PY_mb_hui},
	{"486", "hun", PY_mb_hun},
	{"486", "huo", PY_mb_huo},
	{"542", "jia", PY_mb_jia},
	{"543", "jie", PY_mb_jie},
	{"546", "jin", PY_mb_jin},
	{"548", "jiu", PY_mb_jiu},
	{"583", "jue", PY_mb_jue},
	{"586", "jun", PY_mb_jun},
	{"524", "kai", PY_mb_kai},
	{"526", "kan", PY_mb_kan},
	{"526", "kao", PY_mb_kao},
	{"536", "ken", PY_mb_ken},
	{"568", "kou", PY_mb_kou},
	{"582", "kua", PY_mb_kua},
	{"584", "kui", PY_mb_kui},
	{"586", "kun", PY_mb_kun},
	{"586", "kuo", PY_mb_kuo},
	{"524", "lai", PY_mb_lai},
	{"526", "lan", PY_mb_lan},
	{"526", "lao", PY_mb_lao},
	{"534", "lei", PY_mb_lei},
	{"543", "lie", PY_mb_lie},
	{"546", "lin", PY_mb_lin},
	{"548", "liu", PY_mb_liu},
	{"568", "lou", PY_mb_lou},
	{"583", "lue", PY_mb_lue},
	{"586", "lun", PY_mb_lun},
	{"586", "luo", PY_mb_luo},
	{"624", "mai", PY_mb_mai},
	{"626", "man", PY_mb_man},
	{"626", "mao", PY_mb_mao},
	{"634", "mei", PY_mb_mei},
	{"636", "men", PY_mb_men},
	{"643", "mie", PY_mb_mie},
	{"646", "min", PY_mb_min},
	{"648", "miu", PY_mb_miu},
	{"668", "mou", PY_mb_mou},
	{"624", "nai", PY_mb_nai},
	{"626", "nan", PY_mb_nan},
	{"626", "nao", PY_mb_nao},
	{"634", "nei", PY_mb_nei},
	{"636", "nen", PY_mb_nen},
	{"643", "nie", PY_mb_nie},
	{"646", "nin", PY_mb_nin},
	{"648", "niu", PY_mb_niu},
	{"683", "nue", PY_mb_nue},
	{"686", "nuo", PY_mb_nuo},
	{"724", "pai", PY_mb_pai},
	{"726", "pan", PY_mb_pan},
	{"726", "pao", PY_mb_pao},
	{"734", "pei", PY_mb_pei},
	{"736", "pen", PY_mb_pen},
	{"743", "pie", PY_mb_pie},
	{"746", "pin", PY_mb_pin},
	{"768", "pou", PY_mb_pou},
	{"742", "qia", PY_mb_qia},
	{"743", "qie", PY_mb_qie},
	{"746", "qin", PY_mb_qin},
	{"748", "qiu", PY_mb_qiu},
	{"783", "que", PY_mb_que},
	{"786", "qun", PY_mb_qun},
	{"726", "ran", PY_mb_ran},
	{"726", "rao", PY_mb_rao},
	{"736", "ren", PY_mb_ren},
	{"768", "rou", PY_mb_rou},
	{"784", "rui", PY_mb_rui},
	{"786", "run", PY_mb_run},
	{"786", "ruo", PY_mb_ruo},
	{"724", "sai", PY_mb_sai},
	{"726", "sao", PY_mb_sao},
	{"726", "san", PY_mb_san},
	{"736", "sen", PY_mb_sen},
	{"742", "sha", PY_mb_sha},
	{"743", "she", PY_mb_she},
	{"744", "shi", PY_mb_shi},
	{"748", "shu", PY_mb_shu},
	{"768", "sou", PY_mb_sou},
	{"784", "sui", PY_mb_sui},
	{"786", "sun", PY_mb_sun},
	{"786", "suo", PY_mb_suo},
	{"824", "tai", PY_mb_tai},
	{"826", "tan", PY_mb_tan},
	{"826", "tao", PY_mb_tao},
	{"843", "tie", PY_mb_tie},
	{"868", "tou", PY_mb_tou},
	{"884", "tui", PY_mb_tui},
	{"886", "tun", PY_mb_tun},
	{"886", "tuo", PY_mb_tuo},
	{"924", "wai", PY_mb_wai},
	{"926", "wan", PY_mb_wan},
	{"934", "wei", PY_mb_wei},
	{"936", "wen", PY_mb_wen},
	{"942", "xia", PY_mb_xia},
	{"943", "xie", PY_mb_xie},
	{"946", "xin", PY_mb_xin},
	{"948", "xiu", PY_mb_xiu},
	{"983", "xue", PY_mb_xue},
	{"986", "xun", PY_mb_xun},
	{"926", "yan", PY_mb_yan},
	{"926", "yao", PY_mb_yao},
	{"946", "yin", PY_mb_yin},
	{"968", "you", PY_mb_you},
	{"983", "yue", PY_mb_yue},
	{"986", "yun", PY_mb_yun},
	{"924", "zai", PY_mb_zai},
	{"926", "zan", PY_mb_zan},
	{"926", "zao", PY_mb_zao},
	{"934", "zei", PY_mb_zei},
	{"936", "zen", PY_mb_zen},
	{"942", "zha", PY_mb_zha},
	{"943", "zhe", PY_mb_zhe},
	{"944", "zhi", PY_mb_zhi},
	{"948", "zhu", PY_mb_zhu},
	{"968", "zou", PY_mb_zou},
	{"984", "zui", PY_mb_zui},
	{"986", "zun", PY_mb_zun},
	{"986", "zuo", PY_mb_zuo},
	{"2264", "bang", PY_mb_bang},
	{"2364", "beng", PY_mb_beng},
	{"2426", "bian", PY_mb_bian},
	{"2426", "biao", PY_mb_biao},
	{"2464", "bing", PY_mb_bing},
	{"2264", "cang", PY_mb_cang},
	{"2364", "ceng", PY_mb_ceng},
	{"2424", "chai", PY_mb_chai},
	{"2426", "chan", PY_mb_chan},
	{"2426", "chao", PY_mb_chao},
	{"2436", "chen", PY_mb_chen},
	{"2468", "chou", PY_mb_chou},
	{"2484", "chuai", PY_mb_chuai},
	{"2484", "chui", PY_mb_chui},
	{"2484", "chun", PY_mb_chun},
	{"2486", "chuo", PY_mb_chuo},
	{"2664", "cong", PY_mb_cong},
	{"2826", "cuan", PY_mb_cuan},
	{"3264", "dang", PY_mb_dang},
	{"3364", "deng", PY_mb_deng},
	{"3426", "dian", PY_mb_dian},
	{"3426", "diao", PY_mb_diao},
	{"3464", "ding", PY_mb_ding},
	{"3664", "dong", PY_mb_dong},
	{"3826", "duan", PY_mb_duan},
	{"3264", "fang", PY_mb_fang},
	{"3364", "feng", PY_mb_feng},
	{"4264", "gang", PY_mb_gang},
	{"4364", "geng", PY_mb_geng},
	{"4664", "gong", PY_mb_gong},
	{"4824", "guai", PY_mb_guai},
	{"4826", "guan", PY_mb_guan},
	{"4264", "hang", PY_mb_hang},
	{"4364", "heng", PY_mb_heng},
	{"4664", "hong", PY_mb_hong},
	{"4823", "huai", PY_mb_huai},
	{"4826", "huan", PY_mb_huan},
	{"5426", "jian", PY_mb_jian},
	{"5426", "jiao", PY_mb_jiao},
	{"5464", "jing", PY_mb_jing},
	{"5826", "juan", PY_mb_juan},
	{"5264", "kang", PY_mb_kang},
	{"5364", "keng", PY_mb_keng},
	{"5664", "kong", PY_mb_kong},
	{"5824", "kuai", PY_mb_kuai},
	{"5826", "kuan", PY_mb_kuan},
	{"5264", "lang", PY_mb_lang},
	{"5366", "leng", PY_mb_leng},
	{"5426", "lian", PY_mb_lian},
	{"5426", "liao", PY_mb_liao},
	{"5464", "ling", PY_mb_ling},
	{"5664", "long", PY_mb_long},
	{"5826", "luan", PY_mb_luan},
	{"6264", "mang", PY_mb_mang},
	{"6364", "meng", PY_mb_meng},
	{"6426", "mian", PY_mb_mian},
	{"6426", "miao", PY_mb_miao},
	{"6464", "ming", PY_mb_ming},
	{"6264", "nang", PY_mb_nang},
	{"6364", "neng", PY_mb_neng},
	{"6426", "nian", PY_mb_nian},
	{"6426", "niao", PY_mb_niao},
	{"6464", "ning", PY_mb_ning},
	{"6664", "nong", PY_mb_nong},
	{"6826", "nuan", PY_mb_nuan},
	{"7264", "pang", PY_mb_pang},
	{"7364", "peng", PY_mb_peng},
	{"7426", "pian", PY_mb_pian},
	{"7426", "piao", PY_mb_piao},
	{"7464", "ping", PY_mb_ping},
	{"7426", "qian", PY_mb_qian},
	{"7426", "qiao", PY_mb_qiao},
	{"7464", "qing", PY_mb_qing},
	{"7826", "quan", PY_mb_quan},
	{"7264", "rang", PY_mb_rang},
	{"7364", "reng", PY_mb_reng},
	{"7664", "rong", PY_mb_rong},
	{"7826", "ruan", PY_mb_ruan},
	{"7264", "sang", PY_mb_sang},
	{"7364", "seng", PY_mb_seng},
	{"7424", "shai", PY_mb_shai},
	{"7426", "shan", PY_mb_shan},
	{"7426", "shao", PY_mb_shao},
	{"7436", "shen", PY_mb_shen},
	{"7468", "shou", PY_mb_shou},
	{"7482", "shua", PY_mb_shua},
	{"7484", "shui", PY_mb_shui},
	{"7486", "shun", PY_mb_shun},
	{"7486", "shuo", PY_mb_shuo},
	{"7664", "song", PY_mb_song},
	{"7826", "suan", PY_mb_suan},
	{"8264", "tang", PY_mb_tang},
	{"8364", "teng", PY_mb_teng},
	{"8426", "tian", PY_mb_tian},
	{"8426", "tiao", PY_mb_tiao},
	{"8464", "ting", PY_mb_ting},
	{"8664", "tong", PY_mb_tong},
	{"8826", "tuan", PY_mb_tuan},
	{"9264", "wang", PY_mb_wang},
	{"9364", "weng", PY_mb_weng},
	{"9426", "xian", PY_mb_xiao},
	{"9426", "xiao", PY_mb_xiao},
	{"9464", "xing", PY_mb_xing},
	{"9826", "xuan", PY_mb_xuan},
	{"9264", "yang", PY_mb_yang},
	{"9464", "ying", PY_mb_ying},
	{"9664", "yong", PY_mb_yong},
	{"9826", "yuan", PY_mb_yuan},
	{"9264", "zang", PY_mb_zang},
	{"9364", "zeng", PY_mb_zeng},
	{"9424", "zhai", PY_mb_zhai},
	{"9426", "zhan", PY_mb_zhan},
	{"9426", "zhao", PY_mb_zhao},
	{"9436", "zhen", PY_mb_zhen},
	{"9468", "zhou", PY_mb_zhou},
	{"9482", "zhua", PY_mb_zhua},
	{"9484", "zhui", PY_mb_zhui},
	{"9486", "zhun", PY_mb_zhun},
	{"9486", "zhuo", PY_mb_zhuo},
	{"9664", "zong", PY_mb_zong},
	{"9826", "zuan", PY_mb_zuan},
	{"24264", "chang", PY_mb_chang},
	{"24364", "cheng", PY_mb_cheng},
	{"24664", "chong", PY_mb_chong},
	{"24826", "chuan", PY_mb_chuan},
	{"48264", "guang", PY_mb_guang},
	{"48264", "huang", PY_mb_huang},
	{"54264", "jiang", PY_mb_jiang},
	{"54664", "jiong", PY_mb_jiong},
	{"58264", "kuang", PY_mb_kuang},
	{"54264", "liang", PY_mb_liang},
	{"64264", "niang", PY_mb_niang},
	{"74264", "qiang", PY_mb_qiang},
	{"74664", "qiong", PY_mb_qiong},
	{"74264", "shang", PY_mb_shang},
	{"74364", "sheng", PY_mb_sheng},
	{"74824", "shuai", PY_mb_shuai},
	{"74826", "shuan", PY_mb_shuan},
	{"94264", "xiang", PY_mb_xiang},
	{"94664", "xiong", PY_mb_xiong},
	{"94264", "zhang", PY_mb_zhang},
	{"94364", "zheng", PY_mb_zheng},
	{"94664", "zhong", PY_mb_zhong},
	{"94824", "zhuai", PY_mb_zhuai},
	{"94826", "zhuan", PY_mb_zhuan},
	{"248264", "chuang", PY_mb_chuang},
	{"748264", "shuang", PY_mb_shuang},
	{"948264", "zhuang", PY_mb_zhuang},
	{"", "", PY_mb_space},
	{NULL, NULL, NULL}	//ding  add
};


typedef struct
{
	const u8 *bh23456;
	const u8 *MB;
} T9BH_IDX;


typedef struct
{
	const u8 *HanZi;
	const u8 *MB;
} THanZiThink;


/*����ָ����в���༭*/
/*���������������abc  ��ABC  ���뷨��*/
static void my_AccordPointInsertEdit (const u8 *TheFirstAddrOfBuff, const u8 *pMove, char StartLine, char EndLine, u8 *cursorx, u8 *cursory)
{
	u8 totalline;	//�༭���м���
	int bytenum;	//��buff  ͷ����괦�ж��ٸ��ַ�
	u8 byteline;	//��buff  ͷ����괦��Ҫ���ٸ�����ʾ
	//int bytetotal;	//buff  �ܹ��ж��ٸ��ַ�
	u8 i, j;
	const u8 *display;
	char disp[23];

	*cursorx = 0;
	*cursory = 0;

	totalline = EndLine - StartLine + 1;
	bytenum = pMove - TheFirstAddrOfBuff;
	//bytetotal=strlen(TheFirstAddrOfBuff);

	byteline = bytenum / ALineNum;

	if (bytenum % ALineNum) byteline++;

	display = TheFirstAddrOfBuff;	//�ҳ���Ҫ��ʾ�ĵ�ַ

	if (byteline > totalline)
	{
		for (i = 0; i < byteline - totalline; i++)
		{
			for (j = 0; j < ALineNum; j++, display++)
			{
				if (*display > 0x80)
				{
					display++;
					j++;
				}
			}
		}
	}

#ifdef DEBUG_PRINTF
	printf ("display=%s\n", display);
#endif

	if (*display != 0)  		//������ַ�
	{
		for (i = 0; i < totalline; i++)  			//��ʾpMove  ֮ǰ֮������" ��ʾ��Χ֮��"  ���ַ�
		{
			for (j = 0; j < ALineNum && *display != 0;)
			{
				if (*display > 0x80)
				{
					disp[j] = *display;
					j++;
					display++;

					if (display == pMove)
					{
						*cursory = i;
						*cursorx = j;
					}
				}

				disp[j] = *display;
				j++;
				display++;

				if (display == pMove)
				{
					*cursory = i;
					*cursorx = j;
				}
			}

			for (; j < ALineNum + 2; j++) disp[j] = ' ';			//�˴�ALineNum+1  Ϊ��ȥ��ɾ���ַ��ǣ���������ʾ������ֵ�����

			disp[j] = 0;
#ifdef DEBUG_PRINTF
			printf ("disline=%s\n", disp);
#endif
			text_out_to_row_Language2 ( (unsigned char) StartLine + i, (unsigned char*) disp, (unsigned char*) disp);
		}
	}
	else 		//���û�ַ������п�����ɾ�����ˣ�����Ļ��ʣһ���ַ�
	{
		text_out_to_row_Language2 ( (unsigned char) StartLine, "   ", "   ");
	}

#ifdef DEBUG_PRINTF
	printf ("bytenum=%d\n", bytenum);
#endif

	*cursorx *= 6;
	*cursory += StartLine;
	*cursory *= 13;
	flashcursor (*cursorx, *cursory);
}


static void DisplayContaiPYHaizi (char PYrowcnt, const T9PY_IDX **pT9PY, char *PYbuff, char addid, char pagecnt, char *HaiziRightShiftmax)
{
	int x, i;
	char tb[25];
	const char *pMB;
	char pybuf[8];
	const u8 NumData[10][5] =  		//����ߣ����أ�: 4��5 ����ȡģ���ֽڵ���
	{
		{0x1F,0x11,0x1F,0x00},	//_0
		{0x00,0x1F,0x00,0x00},	//_1
		{0x1D,0x15,0x17,0x00},	//_2
		{0x15,0x15,0x1F,0x00},	//-3	
		{0x07,0x04,0x1F,0x00},	//-4
		{0x17,0x15,0x1D,0x00},	//_5
		{0x1F,0x15,0x1D,0x00},	//_6
		{0x01,0x01,0x1F,0x00},	//_7
		{0x1F,0x15,0x1F,0x00},	//_8
		{0x17,0x15,0x1F,0x00}	//_9
	};

	pMB = PYbuff;

	for (i = 1; i < PYrowcnt;)
	{
		if (*pMB == ' ') i++;

		pMB++;
	}

	memset (pybuf, 0, sizeof (pybuf) );

	for (i = 0; i < 8 && *pMB > ' '; i++, pMB++)
	{
		pybuf[i] = *pMB;
	}

#ifdef DEBUG_PRINTF
	printf ("pybuf=%s\n", pybuf);
#endif

	for (i = 0; t9PY_index[i].T9 != NULL; i++)
	{
		if (strcmp ( (char*) t9PY_index[i].PY, pybuf) == 0)
		{
			break;
		}
	}

	if (t9PY_index[i].T9 != NULL)
	{
#ifdef DEBUG_PRINTF
		printf ("t9PY_index[i].MB!=NULL\n");
#endif
		*pT9PY = &t9PY_index[i];
		pMB = (const char*) t9PY_index[i].MB;
		pMB += pagecnt * 14;
#ifdef DEBUG_PRINTF
		printf ("pMB=%s\n", pMB);
#endif

		if (strlen (pMB) / 2 / 7 > 0) *HaiziRightShiftmax = 6;
		else *HaiziRightShiftmax = strlen (pMB) / 2 % 7 - 1;

		memset (tb, 0, sizeof (tb) );

		for (i = 0; *pMB != 0;)
		{
			tb[i] = ' ';
			i++;
			tb[i] = *pMB;
			i++;
			pMB++;
			tb[i] = *pMB;
			i++;
			pMB++;

			if (i > 20) break;
		}

		clear_area_to_row (MaxRowOneScr - 1, MaxRowOneScr - 1);
		text_out_to_row_Language2 (MaxRowOneScr - 1, (unsigned char*) tb, (unsigned char*) tb);
		if (addid)  			//��ÿ�����ּ���1234567  ���
		{
			for (x = 0, i = 0; i < 20; i++)
			{
				if (tb[i] == 0) break;

				if (tb[i] == ' ')
				{
					draw_pic (NumData[x + 1], x * 18 + 2, 53, 4, 5);
					x++;
				}
			}
		}

		reverse_area_to_row (6, MaxRowOneScr - 1, 12, 14);
		draw_line_to_row (MaxRowOneScr - 2);
	}
}

static void DisplayBH (const char *key09)
{
	const char *pMB;
	char x;
	const u8 heng[6] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x00};
	const u8 shu[6] = {0x00, 0x00, 0xFC, 0x00, 0x00, 0x00};
	const u8 pie[6] = {0x04, 0x08, 0x10, 0x20, 0xC0, 0x00};
	const u8 na[6] = {0xC0, 0x20, 0x10, 0x08, 0x04, 0x00};
	const u8 zhe[6] = {0x80, 0x80, 0x80, 0x84, 0xFC, 0x00};

	pMB = key09;	//�ڵ����ڶ�����ʾ�ʻ�

	for (x = 0; *pMB != '\0'; x += 6, pMB++)
	{
		if (*pMB == '2')		draw_pic (heng, x, 44, 6, 6);
		else if (*pMB == '3')	draw_pic (shu, x, 44, 6, 6);
		else if (*pMB == '4')	draw_pic (pie, x, 44, 6, 6);
		else if (*pMB == '5')	draw_pic (na, x, 44, 6, 6);
		else if (*pMB == '6')	draw_pic (zhe, x, 44, 6, 6);
	}
}
static void DisplayContaiBHHaizi (const T9BH_IDX **pT9BH, char *key09, char addid, char pagecnt, char *HaiziRightShiftmax)
{
	int x, i;
	char tb[25];
	const char *pMB;
	const u8 NumData[10][5] =  		//����ߣ����أ�: 4��5
	{
		{0xF8, 0x88, 0xF8, 0x00},	//_0
		{0x00, 0xF8, 0x00, 0x00},	//_1
		{0xB8, 0xA8, 0xE8, 0x00},	//_2
		{0xA8, 0xA8, 0xF8, 0x00},	//_3
		{0xE0, 0x20, 0xF8, 0x00},	//_4
		{0xE8, 0xA8, 0xB8, 0x00},	//_5
		{0xF8, 0xA8, 0xB8, 0x00},	//_6
		{0x80, 0x80, 0xF8, 0x00},	//_7
		{0xF8, 0xA8, 0xF8, 0x00},	//_8
		{0xE8, 0xA8, 0xF8, 0x00}	//_9
	};

	DisplayBH (key09);	//�˴���key09  ������pT9BH  ����Ϊ��"662446"  ������ϣ��ʻ���ʾ�������⡣

	pMB = (const char*) (*pT9BH)->MB;
	pMB += pagecnt * 14;
#ifdef DEBUG_PRINTF
	printf ("pMB=%s\n", pMB);
#endif

	if (strlen (pMB) / 2 / 7 > 0) *HaiziRightShiftmax = 6;
	else *HaiziRightShiftmax = strlen (pMB) / 2 % 7 - 1;

	memset (tb, 0, sizeof (tb) );

	for (i = 0; *pMB != 0;)
	{
		tb[i] = ' ';
		i++;
		tb[i] = *pMB;
		i++;
		pMB++;
		tb[i] = *pMB;
		i++;
		pMB++;

		if (i > 20) break;
	}

	clear_area_to_row (MaxRowOneScr - 1, MaxRowOneScr - 1);
	text_out_to_row_Language2 (MaxRowOneScr - 1, (unsigned char*) tb, NULL);

	if (addid)  		//��ÿ�����ּ���1234567  ���
	{
		for (x = 0, i = 0; i < 20; i++)
		{
			if (tb[i] == 0) break;

			if (tb[i] == ' ')
			{
				draw_pic (NumData[x + 1], x * 18 + 2, 53, 4, 5);
				x++;
			}
		}
	}

	reverse_area_to_row (6, MaxRowOneScr - 1, 12, 14);
	draw_line_to_row (MaxRowOneScr - 2);
}


static void HighLightPY (const char *buff, char newpy)
{
	const char *buffStart, *buffPY;
	char diplaybuff[22];
	u8 i, j, zifunum;
	char temp, xpos = 0;
	char sjxflag = 0;	//�����Ƶ������α�־
	const char leftsjx[] = {0x10, 0x38, 0x7C, 0xFE, 0x00};
	const char rightsjx[] = {0xFE, 0x7C, 0x38, 0x10, 0x00};

	buffPY = buff;	//������ж��ٸ�ƴ���������:  "piao pian qian qiao shan shao "  ��ôzifunum=4��
	zifunum = 0;

	while (*buffPY != ' ')
	{
		zifunum++;
		buffPY++;
	}

	buffPY = buff;	//�ҳ�Ҫ��ʾƴ����λ�á�

	for (i = 1; i < newpy;)
	{
		if (*buffPY == ' ') i++;

		buffPY++;
	}

	buffStart = buff;	//�ҳ�Ҫ�������ַ�������ʼ��ַ
	temp = newpy;

	if (buffPY - buffStart + zifunum > 19)
	{
		sjxflag |= 0x01;		//Ҫ��ʾ��ߵ������Ρ�

		for (i = 1; i < newpy && *buffStart != 0;)
		{
			buffStart++;

			if (*buffStart == ' ')
			{
				i++;
				temp--;

				if (buffPY - buffStart + zifunum <= 20)
				{
					buffStart++;
					break;
				}
			}
		}
	}

	for (i = 0; i < 19 && *buffStart != 0; i++)  		//�����ַ�����diplaybuff
	{
		diplaybuff[i] = *buffStart;
		buffStart++;
	}

	for (; i < 20; i++) diplaybuff[i] = ' ';

	diplaybuff[i] = 0;

	while (*buffStart != 0)  		//�ж��Ƿ�Ҫ��ʾ�ұߵ������Ρ�
	{
		if (*buffStart >= 'a' && *buffStart <= 'z')
		{
			sjxflag |= 0x02;
			break;
		}

		buffStart++;
	}

	xpos = 0;

	for (j = 0, i = 1; i < temp;)  		//���������x  ����λ��
	{
		if (diplaybuff[j] == ' ')
		{
			i++;
		}

		xpos++;
		j++;
	}

	text_out_to_row_x_Language2 (MaxRowOneScr - 2, 6, (unsigned char*) diplaybuff, (unsigned char*)diplaybuff);
	reverse_area_to_row (xpos * 6 + 6, MaxRowOneScr - 2, zifunum * 6 + 2, 12);

	if (sjxflag & 0x01)
	{
		draw_pic ( (unsigned char*) leftsjx, 0, 43, 5, 7);
	}
	else
	{
		clear_area (0, 43, 5, 7);
	}

	if (sjxflag & 0x02)
	{
		draw_pic ( (unsigned char*) rightsjx, 124, 43, 5, 7);
	}
	else
	{
		clear_area (124, 43, 5, 7);
	}
}


static void CalculateCursorOffset (char srf)
{
	signed int x = cursorX, y = cursorY;

	if (srf == SRF_BiHua || srf == SRF_PY) x += 12;
	else x += 6;

	if (x >= 6 * ALineNum)
	{
		x = 0;
		y *= 13;

		if (y >= (EditAreaTotalRow + 1) * 13) y = EditAreaTotalRow * 13;
	}

#ifdef DEBUG_PRINTF
	printf ("cursorX=%d,cursorY=%d\n", x, y);
#endif

	flashcursor (x, y);
}


static u8 PinYinReadCode (char PyCode[3]) //ƴ�����뷨������
{
	char key09[10], keyflag, PYnum, strcpyflag, confirmflag = 0, rowcnt, pagecnt = 0, youcipinyinzuohe;
	char PYrowcnt, PYbuff[100];
	int i;
	const T9PY_IDX *pT9PY = NULL;
	char HaiziRightShiftmax;	//�����������ֵ
	u8 keycnt = 0;
	u8 keyval;
	u8 flag = 1;

	memset (key09, 0, sizeof (key09) );

	while (1)
	{
		keyval = GetKeyValue();

		if (keyval == 0) continue;

		if (flag == 1)
		{
			flag = 0;
			KeyEventPost_nobeep();
		}
		else
		{
			KeyEventPost();
		}

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				key09[keycnt++] = '0';
				break;

			case KEY1:
				keyflag = 1;
				key09[keycnt++] = '1';
				break;

			case KEY2:
				keyflag = 1;
				key09[keycnt++] = '2';
				break;

			case KEY3:
				keyflag = 1;
				key09[keycnt++] = '3';
				break;

			case KEY4:
				keyflag = 1;
				key09[keycnt++] = '4';
				break;

			case KEY5:
				keyflag = 1;
				key09[keycnt++] = '5';
				break;

			case KEY6:
				keyflag = 1;
				key09[keycnt++] = '6';
				break;

			case KEY7:
				keyflag = 1;
				key09[keycnt++] = '7';
				break;

			case KEY8:
				keyflag = 1;
				key09[keycnt++] = '8';
				break;

			case KEY9:
				keyflag = 1;
				key09[keycnt++] = '9';
				break;

			case KEYXING:
				keyflag = 1;
				keycnt = 1;
				key09[0] = '*';
				key09[1] = 0;
				break;

			case KEYJING:	//#�л����뷨
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return KEYJING;

			case KEY_UP:			//�����Ϸ�ҳ
				if (pagecnt && confirmflag == 2)
				{
					pagecnt--;
					rowcnt = 0;
					DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 1, pagecnt, &HaiziRightShiftmax);
				}

				break;

			case KEY_DOWN:			//�����·�ҳ
				if (pagecnt < (strlen ( (char*) pT9PY->MB) - 2) / 14 && confirmflag == 2)  				//�˴���2  Ϊ������պ�һ�����û�
				{
					pagecnt++;
					rowcnt = 0;
					DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 1, pagecnt, &HaiziRightShiftmax);
#ifdef DEBUG_PRINTF
					printf ("pT9PY->MB=%s\r\n", pT9PY->MB);
#endif
				}

				break;

			case KEY_LEFT:
				if (confirmflag == 1)  				//ƴ����������
				{
					if (PYrowcnt > 1)
					{
						PYrowcnt--;
						HighLightPY (PYbuff, PYrowcnt);
						DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 0, pagecnt, &HaiziRightShiftmax);
					}
				}
				else if (confirmflag == 2)  				//���ָ�������
				{
					if (rowcnt)
					{
						rowcnt--;
						reverse_area_to_row (6 + 18 * (rowcnt + 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * rowcnt, MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_RIGHT:
				if (confirmflag == 1)  				//ƴ����������
				{
					if (PYrowcnt < PYnum)
					{
						PYrowcnt++;
						HighLightPY (PYbuff, PYrowcnt);printf("PYbuff=%s,PYrowcnt=%d\r\n",PYbuff,PYrowcnt);
						DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 0, pagecnt, &HaiziRightShiftmax);
					}
				}
				else if (confirmflag == 2)  				//���ָ�������
				{
					if (pT9PY != NULL && rowcnt < HaiziRightShiftmax)
					{
						rowcnt++;
						reverse_area_to_row (6 + 18 * (rowcnt - 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * (rowcnt), MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_Enter:
				keyflag = 4;
				break;

			case KEY_DEL:	//ɾ����
				if (keycnt <= 1)  				//ɾ������󣬾ͷ���
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);	//ƴ������ռ��������У������˳�ʱ���
					return KEY_DEL;
				}
				else 				//ɾ��һ��ƴ����ĸ
				{
					confirmflag = 1;
					keyflag = 1;
					keycnt--;
					key09[keycnt] = 0;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return keyval;
		}

		if (keyflag == 1)
		{
			if (confirmflag == 2)  				//1---7ѡ����
			{
#ifdef DEBUG_PRINTF
				printf ("key09[keycnt-1]=%c\r\n", key09[keycnt - 1]);
#endif

				if (key09[keycnt - 1] >= '1' && key09[keycnt - 1] <= '7')
				{
					i = key09[keycnt - 1] - '1';
					memset (PyCode, 0, 3);
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
#ifdef DEBUG_PRINTF
					printf ("pagecnt=%d\r\n", pagecnt);
					printf ("pT9PY->MB=%s\r\n", pT9PY->MB);
					printf ("i=%d\r\n", i);
#endif
					memcpy (PyCode, pT9PY->MB + pagecnt * 14 + i * 2, 2);
					CalculateCursorOffset (SRF_PY);
					return KEY_Enter;
				}
			}
			else 				//ƴ������
			{
				rowcnt = 0;

				if (keycnt > sizeof (key09) - 1) keycnt = sizeof (key09) - 1;

				if (keycnt == 0)
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
				}
				else
				{
					strcpyflag = 0;
					youcipinyinzuohe = 0;

					for (i = 0; t9PY_index[i].T9 != NULL; i++)
					{
						if (strcmp ( (char*) t9PY_index[i].T9, key09) == 0)
						{
							if (!strcpyflag)
							{
								strcpyflag = 1;
								pT9PY = &t9PY_index[i];
								strcpy (PYbuff, (char*) t9PY_index[i].PY);
							}
							else strcat (PYbuff, (char*) t9PY_index[i].PY);

							strcat (PYbuff, " ");
							youcipinyinzuohe = 1;
						}
					}

					if (!youcipinyinzuohe)
					{
						for (i = 0; t9PY_index[i].T9 != NULL; i++)
						{
							if (my_FFstrstr ( (char*) t9PY_index[i].T9, key09) )
							{
								if (!strcpyflag)
								{
									strcpyflag = 1;
									pT9PY = &t9PY_index[i];
									strcpy (PYbuff, (char*) t9PY_index[i].PY);
								}
								else strcat (PYbuff, (char*) t9PY_index[i].PY);

								strcat (PYbuff, " ");
								youcipinyinzuohe = 1;
								break;
							}
						}

						if (!youcipinyinzuohe)
						{
							keycnt--;
							key09[keycnt] = 0;
						}
					}

					if (youcipinyinzuohe)
					{
						pagecnt = 0;
						clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
						PYnum = my_KonggeStrlen (PYbuff);

						if (PYnum)
						{
							PYrowcnt = 1;
							confirmflag = 1;
							HighLightPY (PYbuff, 1);
							DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 0, pagecnt, &HaiziRightShiftmax);
						}
					}
				}
			}
		}
		else if (keyflag == 4)  			//KEY_Enter
		{
			if (confirmflag == 1)  				//��һ�ΰ�ȷ�ϣ�������ʾ�ĺ��ּ������ֱ�ʾ��
			{
				DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 1, pagecnt, &HaiziRightShiftmax);
				confirmflag = 2;
			}
			else 				//�ڶ��ΰ�ȷ�ϣ�ѡ��������ĺ��ַ��ء�
			{
				memset (PyCode, 0, 3);
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				memcpy (PyCode, pT9PY->MB + pagecnt * 14 + rowcnt * 2, 2);
				CalculateCursorOffset (SRF_PY);
				return KEY_Enter;
			}
		}

#ifdef DEBUG_PRINTF
		printf ("key09=%s\r\n", key09);
#endif

		KeyIsResponse();
	}
}


//0---->9  ��*�����˺���
static u8 BiHuaReadCode (char PyCode[3]) //�ʻ����뷨������
{
	char key09[15], keyflag, confirmflag = 0, rowcnt, pagecnt = 0;
	int i;
	const T9BH_IDX *pT9BH = NULL;
	char HaiziRightShiftmax;	//�����������ֵ
	u8 keycnt = 0;
	u8 keyval;
	u8 flag = 1;

	memset (key09, 0, sizeof (key09) );

	while (1)
	{
		keyval = GetKeyValue();

		if (keyval == 0) continue;

		if (flag == 1)
		{
			flag = 0;
			KeyEventPost_nobeep();
		}
		else
		{
			KeyEventPost();
		}

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				key09[keycnt++] = '0';
				break;

			case KEY1:
				keyflag = 1;
				key09[keycnt++] = '1';
				break;

			case KEY2:
				keyflag = 1;
				key09[keycnt++] = '2';
				break;

			case KEY3:
				keyflag = 1;
				key09[keycnt++] = '3';
				break;

			case KEY4:
				keyflag = 1;
				key09[keycnt++] = '4';
				break;

			case KEY5:
				keyflag = 1;
				key09[keycnt++] = '5';
				break;

			case KEY6:
				keyflag = 1;
				key09[keycnt++] = '6';
				break;

			case KEY7:
				keyflag = 1;
				key09[keycnt++] = '7';
				break;

			case KEYXING:
				keyflag = 1;
				keycnt = 1;
				key09[0] = '*';
				key09[1] = 0;
				break;

			case KEYJING:	//#�л����뷨
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return KEYJING;

			case KEY_UP:			//�����Ϸ�ҳ
				if (pagecnt && confirmflag == 2)
				{
					pagecnt--;
					rowcnt = 0;
					DisplayContaiBHHaizi (&pT9BH, key09, 1, pagecnt, &HaiziRightShiftmax);
				}

				break;

			case KEY_DOWN:			//�����·�ҳ
				if (pagecnt < (strlen ( (char*) pT9BH->MB) - 2) / 14 && confirmflag == 2)  				//�˴���2  Ϊ������պ�һ�����û�
				{
					pagecnt++;
					rowcnt = 0;
					DisplayContaiBHHaizi (&pT9BH, key09, 1, pagecnt, &HaiziRightShiftmax);
#ifdef DEBUG_PRINTF
					printf ("pT9BH->MB=%s\n", pT9BH->MB);
#endif
				}

				break;

			case KEY_LEFT:
				if (confirmflag == 2)  		//���ָ�������
				{
					if (rowcnt)
					{
						rowcnt--;
						reverse_area_to_row (6 + 18 * (rowcnt + 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * rowcnt, MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_RIGHT:
				if (confirmflag == 2)  		//���ָ�������
				{
					if (pT9BH != NULL && rowcnt < HaiziRightShiftmax)
					{
						rowcnt++;
						reverse_area_to_row (6 + 18 * (rowcnt - 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * (rowcnt), MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_Enter:
				keyflag = 4;
				break;

			case KEY_DEL:	//ɾ����
				if (keycnt <= 1)  		//ɾ������󣬾ͷ���
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);				//�ʻ�����ռ��������У������˳�ʱ���
					return KEY_DEL;
				}
				else 				//ɾ��һ���ʻ�
				{
					confirmflag = (keycnt - 1) * 6;
					clear_area (confirmflag, 44, 6, 6);				//������һ���ʻ�
					confirmflag = 1;
					keyflag = 1;
					keycnt--;
					key09[keycnt] = 0;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return keyval;
		}

		if (keyflag == 1)
		{
			if (confirmflag == 2)  				//1---7ѡ����
			{
#ifdef DEBUG_PRINTF
				printf ("key09[keycnt-1]=%c\n", key09[keycnt - 1]);
#endif

				if (key09[keycnt - 1] >= '1' && key09[keycnt - 1] <= '7')
				{
					i = key09[keycnt - 1] - '1';
					memset (PyCode, 0, 3);
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
#ifdef DEBUG_PRINTF
					printf ("pagecnt=%d\n", pagecnt);
					printf ("pT9BH->MB=%s\n", pT9BH->MB);
					printf ("i=%d\n", i);
#endif
					memcpy (PyCode, pT9BH->MB + pagecnt * 14 + i * 2, 2);
					CalculateCursorOffset (SRF_PY);
					return KEY_Enter;
				}
			}
		}
		else if (keyflag == 4)  			//KEY_Enter
		{
			if (confirmflag == 1)  				//��һ�ΰ�ȷ�ϣ�������ʾ�ĺ��ּ������ֱ�ʾ��
			{
				DisplayContaiBHHaizi (&pT9BH, key09, 1, pagecnt, &HaiziRightShiftmax);
				confirmflag = 2;
			}
			else 				//�ڶ��ΰ�ȷ�ϣ�ѡ��������ĺ��ַ��ء�
			{
				memset (PyCode, 0, 3);
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
				memcpy (PyCode, pT9BH->MB + pagecnt * 14 + rowcnt * 2, 2);
				CalculateCursorOffset (SRF_BiHua);
				return KEY_Enter;
			}
		}

#ifdef DEBUG_PRINTF
		printf ("key09=%s\n", key09);
#endif

		KeyIsResponse();
	}
}


void flashcursor (signed int x, signed int y)
{
	cursorX = x;
	cursorY = y;
}


static void srf_strcat_insert (unsigned char *pMove, const unsigned char *PyCode)
{
	unsigned char insertlen;
	unsigned int pMovelen;

	const unsigned char *psrc;
	unsigned char *pdes;

	insertlen = strlen ( (const char*) PyCode);
	pMovelen = strlen ( (const char*) pMove);

	if (pMovelen)
	{
		psrc = pMove + pMovelen - 1;
		pdes = pMove + pMovelen + insertlen - 1;

		for (; pMovelen != 0; pMovelen--)
		{
			*pdes = *psrc;
			psrc--;
			pdes--;
		}
	}

	memcpy (pMove, PyCode, insertlen);
}


#else
static void srf_strcat_insert (unsigned char *pMove, const unsigned char *PyCode)
{
	unsigned char insertlen;
	unsigned int pMovelen;

	const unsigned char *psrc;
	unsigned char *pdes;

	insertlen = strlen ( (const char*) PyCode);
	pMovelen = strlen ( (const char*) pMove);

	if (pMovelen)
	{
		psrc = pMove + pMovelen - 1;
		pdes = pMove + pMovelen + insertlen - 1;

		for (; pMovelen != 0; pMovelen--)
		{
			*pdes = *psrc;
			psrc--;
			pdes--;
		}
	}

	memcpy (pMove, PyCode, insertlen);
}


static void CalculateCursorOffset (char srf)
{
	signed int x = cursorX, y = cursorY;

	if (srf == SRF_BiHua || srf == SRF_PY) x += 12;
	else x += 6;

	if (x >= 6 * ALineNum)
	{
		x = 0;
		y *= 13;

		if (y >= (EditAreaTotalRow + 1) * 13) y = EditAreaTotalRow * 13;
	}

#ifdef DEBUG_PRINTF
	printf ("cursorX=%d,cursorY=%d\n", x, y);
#endif

	flashcursor (x, y);
}

void flashcursor (signed int x, signed int y)
{
	cursorX = x;
	cursorY = y;
}

/*����ָ����в���༭*/
/*���������������abc  ��ABC  ���뷨��*/
static void my_AccordPointInsertEdit (const u8 *TheFirstAddrOfBuff, const u8 *pMove, char StartLine, char EndLine, u8 *cursorx, u8 *cursory)
{
	u8 totalline;	//�༭���м���
	int bytenum;	//��buff  ͷ����괦�ж��ٸ��ַ�
	u8 byteline;	//��buff  ͷ����괦��Ҫ���ٸ�����ʾ
	//int bytetotal;	//buff  �ܹ��ж��ٸ��ַ�
	u8 i, j;
	const u8 *display;
	u8 disp[23];

	*cursorx = 0;
	*cursory = 0;

	totalline = EndLine - StartLine + 1;
	bytenum = pMove - TheFirstAddrOfBuff;
	//bytetotal=strlen((char const*)TheFirstAddrOfBuff);

	byteline = bytenum / ALineNum;

	if (bytenum % ALineNum) byteline++;

	display = TheFirstAddrOfBuff;	//�ҳ���Ҫ��ʾ�ĵ�ַ

	if (byteline > totalline)
	{
		for (i = 0; i < byteline - totalline; i++)
		{
			for (j = 0; j < ALineNum; j++, display++)
			{
				if (*display > 0x80)
				{
					display++;
					j++;
				}
			}
		}
	}

#ifdef DEBUG_PRINTF
	printf ("display=%s\n", display);
#endif

	if (*display != 0)  		//������ַ�
	{
		for (i = 0; i < totalline; i++)  			//��ʾpMove  ֮ǰ֮������" ��ʾ��Χ֮��"  ���ַ�
		{
			for (j = 0; j < ALineNum && *display != 0;)
			{
				if (*display > 0x80)
				{
					disp[j] = *display;
					j++;
					display++;

					if (display == pMove)
					{
						*cursory = i;
						*cursorx = j;
					}
				}

				disp[j] = *display;
				j++;
				display++;

				if (display == pMove)
				{
					*cursory = i;
					*cursorx = j;
				}
			}

			for (; j < ALineNum + 2; j++) disp[j] = ' ';			//�˴�ALineNum+1  Ϊ��ȥ��ɾ���ַ��ǣ���������ʾ������ֵ�����

			disp[j] = 0;
#ifdef DEBUG_PRINTF
			printf ("disline=%s\n", disp);
#endif
			text_out_to_row_Language2 (StartLine + i, disp, disp);
		}
	}
	else 		//���û�ַ������п�����ɾ�����ˣ�����Ļ��ʣһ���ַ�
	{
		text_out_to_row_Language2 (StartLine, "   ", "   ");
	}

#ifdef DEBUG_PRINTF
	printf ("bytenum=%d\n", bytenum);
#endif

	*cursorx *= 6;
	*cursory += StartLine;
	*cursory *= 13;
	flashcursor (*cursorx, *cursory);
}

#endif

static void flashguangbiao_to_row (u8 x, u8 row)
{
	flashcursor (x, 13 * row);
}

static u8 abcABCflag = 0;

static u8 abcReadCode (const u8 *BuffTheFirstAddr, u8 *pMove)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.:%1@/?;\'\"|\\{[}]=+-_)(*&^$#!~`<>",
		"abc2",
		"def3",
		"ghi4",
		"jkl5",
		"mno6",
		"pqrs7",
		"tuv8",
		"wxyz9"
	};

	CalculateCursorOffset (SRF_abc);	//�������������뵽����ض��᷵��һ��asccii  ��
	x = pMove - BuffTheFirstAddr;

	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert (pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, 1, 2, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12);				//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}

static u8 ABCReadCode (const u8 *BuffTheFirstAddr, u8 *pMove)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.:%1@/?;\'\"|\\{[}]=+-_)(*&^$#!~`<>",
		"ABC2",
		"DEF3",
		"GHI4",
		"JKL5",
		"MNO6",
		"PQRS7",
		"TUV8",
		"WXYZ9"
	};

	CalculateCursorOffset (SRF_ABC);	//�������������뵽����ض��᷵��һ��asccii  ��
	x = pMove - BuffTheFirstAddr;
#ifdef DEBUG_PRINTF
	printf ("len=%d\n", x);
#endif
	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert ( (unsigned char*) pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, 1, 2, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12);				//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}

static u8 _123ReadCode (u8 PyCode[3], u8 keyval)
{
	memset (PyCode, 0, 3);

	switch (keyval)
	{
		case KEY0:
			PyCode[0] = '0';
			break;

		case KEY1:
			PyCode[0] = '1';
			break;

		case KEY2:
			PyCode[0] = '2';
			break;

		case KEY3:
			PyCode[0] = '3';
			break;

		case KEY4:
			PyCode[0] = '4';
			break;

		case KEY5:
			PyCode[0] = '5';
			break;

		case KEY6:
			PyCode[0] = '6';
			break;

		case KEY7:
			PyCode[0] = '7';
			break;

		case KEY8:
			PyCode[0] = '8';
			break;

		case KEY9:
			PyCode[0] = '9';
			break;

		case KEYXING:
			PyCode[0] = '.';
			break;
	}

	if ( (PyCode[0] >= '0' && PyCode[0] <= '9') || PyCode[0] == '.')
	{
		CalculateCursorOffset (SRF_123);
		return KEY_Enter;
	}
	else return KEY_ReturnInitInterface;
}

static u8 _123TimeInput (u8 PyCode[3], u8 keyval)
{
	memset (PyCode, 0, 3);

	switch (keyval)
	{
		case KEY0:
			PyCode[0] = '0';
			break;

		case KEY1:
			PyCode[0] = '1';
			break;

		case KEY2:
			PyCode[0] = '2';
			break;

		case KEY3:
			PyCode[0] = '3';
			break;

		case KEY4:
			PyCode[0] = '4';
			break;

		case KEY5:
			PyCode[0] = '5';
			break;

		case KEY6:
			PyCode[0] = '6';
			break;

		case KEY7:
			PyCode[0] = '7';
			break;

		case KEY8:
			PyCode[0] = '8';
			break;

		case KEY9:
			PyCode[0] = '9';
			break;

		case KEYXING:
			PyCode[0] = ':';
			break;
	}

	if ( (PyCode[0] >= '0' && PyCode[0] <= '9') || PyCode[0] == ':')
	{
		CalculateCursorOffset (SRF_123);
		return KEY_Enter;
	}
	else return KEY_ReturnInitInterface;
}

typedef struct
{
	const char srf[5];
	char Enable;
} T_ShuRuFa;


static u8 *GetSrfString (u8 currentSrf)
{
	if (currentSrf == SRF_PY) return "ƴ��";
	else if (currentSrf == SRF_123) return "123 ";
	else if (currentSrf == SRF_abc) return "abc ";
	else if (currentSrf == SRF_ABC) return "ABC ";
	else if (currentSrf == SRF_BiHua) return "�ʻ�";
	else return "abc ";
}

static void DisplaySrfAndInput (u8 currentSrf)
{
	clear_area_to_row (MaxRowOneScr - 1, MaxRowOneScr - 1);
	text_out_to_row_x (MaxRowOneScr - 1, 0, GetSrfString (currentSrf) );
	reverse_area_to_row (0, MaxRowOneScr - 1, 25, 16);
	text_out_to_row_x (MaxRowOneScr - 1, 60, "input...");
}

static u8 SwitchSrf (u8 VolidSrf, u8 currentSrf)
{
	if (currentSrf == SRF_PY)
	{
		if (VolidSrf & SRF_123) return SRF_123;
		else if (VolidSrf & SRF_abc) return SRF_abc;
		else if (VolidSrf & SRF_ABC) return SRF_ABC;
		else if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else return SRF_PY;
	}
	else if (currentSrf == SRF_123)
	{
		if (VolidSrf & SRF_abc) return SRF_abc;
		else if (VolidSrf & SRF_ABC) return SRF_ABC;
		else if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else if (VolidSrf & SRF_PY) return SRF_PY;
		else return SRF_123;
	}
	else if (currentSrf == SRF_abc)
	{
		if (VolidSrf & SRF_ABC) return SRF_ABC;
		else if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else if (VolidSrf & SRF_PY) return SRF_PY;
		else if (VolidSrf & SRF_123) return SRF_123;
		else return SRF_abc;
	}
	else if (currentSrf == SRF_ABC)
	{
		if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else if (VolidSrf & SRF_PY) return SRF_PY;
		else if (VolidSrf & SRF_123) return SRF_123;
		else if (VolidSrf & SRF_abc) return SRF_abc;
		else return SRF_ABC;
	}
	else if (currentSrf == SRF_BiHua)
	{
		if (VolidSrf & SRF_PY) return SRF_PY;
		else if (VolidSrf & SRF_123) return SRF_123;
		else if (VolidSrf & SRF_abc) return SRF_abc;
		else if (VolidSrf & SRF_ABC) return SRF_ABC;
		else return SRF_BiHua;
	}
	else
	{
		return SRF_abc;
	}
}


static void flightcursor (void)
{
	static unsigned int PreviousMs;
	unsigned int CurrentMs;

	CurrentMs = my_GetCurrentMs();

	if (CurrentMs > PreviousMs && CurrentMs - PreviousMs >= 500)
	{
		PreviousMs = CurrentMs;
		reverse_area (cursorX, cursorY, 1, 12);
	}
}

u8 _GetString_abcABC123PYWuBi (u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	int x;
	u8 keyflag;
	u8 cursorx, cursory;
	u8 inputCode[3];
	u8 i = 0;
	u8 *pMove;
	u8 ChineseThinkFlag = 0;
	u8 keyval;
	u8 currentSrf;

	currentSrf = DefaultSrf;
	DisplaySrfAndInput (currentSrf);

	if (HaveoldFlag)
	{
		x = strlen ( (sc8*) receive);
		memset (receive + x, 0, recSize - x);		//ϴ����������receive  ���������õ�β�����ݡ�
	}
	else
	{
		x = 0;
		memset (receive, 0, recSize);
	}

	flashguangbiao_to_row (0, EditAreaStartLine);
	pMove = receive + x;
	PostKey (KEY_pseudo);

	while (1)
	{
		flightcursor();
		keyval = GetKeyValue();

		if (keyval == KEY_NONE) continue;

		if (keyval != KEY_pseudo)
		{
			if (beepKG[0] == '1')
			{
				if (abcABCflag == 0) BeepNormal();

				abcABCflag = 0;
			}

			kmy_LcdBlackLightOn();
			kmy_AutoOffLcdLight (120);
			kmy_AutoPostKey (120);
		}

		keyflag = KEY_NONE;

		switch (keyval)
		{
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
			case KEYXING:
				if (ChineseThinkFlag == 0)
				{
	loop:

					if (strlen ( (sc8*) receive) < recSize - 1)  		//�˴�recSize  Ϊ�ַ���������
					{
						if (currentSrf == SRF_PY)  						//ƴ��
						{
#ifdef AddBiHuaPinYin
							PostKey (keyval);
							keyval = PinYinReadCode ( (char*) inputCode);
#endif
						}
						else if (currentSrf == SRF_BiHua)  			//�ʻ�
						{
#ifdef AddBiHuaPinYin
							PostKey (keyval);
							keyval = BiHuaReadCode ( (char*) inputCode);
#endif
						}
						else if (currentSrf == SRF_abc)  				//abc
						{
							pMove++;
							PostKey (keyval);
							keyval = abcReadCode (receive, pMove);

							if (keyval != KEY_NONE && keyval != KEYJING)
							{
								goto loop;
							}
						}
						else if (currentSrf == SRF_ABC)  				//ABC
						{
							pMove++;
							PostKey (keyval);
							keyval = ABCReadCode (receive, pMove);

							if (keyval != KEY_NONE && keyval != KEYJING)
							{
								goto loop;
							}
						}
						else if (currentSrf == SRF_123)  				//123
						{
							keyval = _123ReadCode (inputCode, keyval);
						}

						if (keyval == KEY_Enter)
						{
							srf_strcat_insert (pMove, inputCode);

							if (*pMove > 0x80) pMove += 2;
							else pMove++;

							keyflag = 2;
						}
						else if (keyval == KEY_DEL)
						{
							keyflag = 2;
						}
						else if (keyval == KEYJING)
						{
							keyflag = 1;
						}
					}
				}

				break;

			case KEYJING:	//#�л����뷨
				keyflag = 1;
				break;

			case KEY_Enter:	//ȷ�Ϸ���
				return KEY_Enter;

			case KEY_UP:			//�������
				if (ChineseThinkFlag == 0)
				{
					if (pMove - receive > ALineNum)
					{
						for (i = 0; i < ALineNum; i++)
						{
							if (* (pMove - 1) > 0x80)  							//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�
							{
								pMove--;
								i++;
							}

							pMove--;
						}
					}
				}

				break;

			case KEY_DOWN:			//�������
				if (ChineseThinkFlag == 0)
				{
					for (i = 0; i < ALineNum && *pMove != 0; i++)
					{
						if (*pMove > 0x80)
						{
							pMove++;
							i++;
						}

						pMove++;
					}
				}

				break;

			case KEY_LEFT:			//�������
				if (pMove > receive)
				{
					if (* (pMove - 1) > 0x80) pMove--;				//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�

					pMove--;
				}

				break;

			case KEY_RIGHT:			//�������
				if (*pMove)
				{
					if (*pMove > 0x80) pMove++;

					pMove++;
				}

				break;
				
			case KEY_DEL:
				x = strlen ( (sc8*) receive);

				if (x != 0)
				{
					if (pMove > receive)
					{
						if (*pMove != 0)  						//������ַ���֮��ɾ��
						{
							if (* (pMove - 1) > 0x80)
							{
								pMove -= 2;
								my_strcpy_DeleteTailByte (pMove, pMove + 2);
							}
							else
							{
								pMove -= 1;
								my_strcpy_DeleteTailByte (pMove, pMove + 1);
							}
						}
						else
						{
							if (pMove > receive && * (pMove - 1) > 0x80)  							//delete a Chinese character
							{
								pMove--;
								*pMove = 0;
							}

							pMove--;
							*pMove = 0;
						}
					}
				}
				else
				{
					return KEY_LEFT;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1 || (keyflag == 2 && currentSrf != 4) )
		{
			if (keyflag == 1)
			{
				currentSrf = SwitchSrf (srfFlag, currentSrf);
			}

			DisplaySrfAndInput (currentSrf);
		}

		my_AccordPointInsertEdit (receive, pMove, 1, 2, &cursorx, &cursory);
		KeyIsResponse();
	}
}
u8 _GetString_123TimeInput (u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	int x;
	u8 keyflag;
	u8 cursorx, cursory;
	u8 inputCode[3];
	u8 i = 0;
	u8 *pMove;
	u8 ChineseThinkFlag = 0;
	u8 keyval;
	u8 currentSrf;

	currentSrf = DefaultSrf;
	DisplaySrfAndInput (currentSrf);

	if (HaveoldFlag)
	{
		x = strlen ( (sc8*) receive);
		memset (receive + x, 0, recSize - x);		//ϴ����������receive  ���������õ�β�����ݡ�
	}
	else
	{
		x = 0;
		memset (receive, 0, recSize);
	}

	flashguangbiao_to_row (0, EditAreaStartLine);
	pMove = receive + x;
	PostKey (KEY_pseudo);

	while (1)
	{
		flightcursor();
		keyval = GetKeyValue();

		if (keyval == KEY_NONE) continue;

		if (keyval != KEY_pseudo)
		{
			if (beepKG[0] == '1')
			{
				if (abcABCflag == 0) BeepNormal();

				abcABCflag = 0;
			}

			kmy_LcdBlackLightOn();
			kmy_AutoOffLcdLight (120);
			kmy_AutoPostKey (120);
		}

		keyflag = KEY_NONE;

		switch (keyval)
		{
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
			case KEYXING:
				if (ChineseThinkFlag == 0)
				{

					if (strlen ( (sc8*) receive) < recSize - 1)  		//�˴�recSize  Ϊ�ַ���������
					{						
						 if (currentSrf == SRF_123)  				//123
						{
							keyval = _123TimeInput (inputCode, keyval);
						}

						if (keyval == KEY_Enter)
						{
							srf_strcat_insert (pMove, inputCode);

							if (*pMove > 0x80) pMove += 2;
							else pMove++;

							keyflag = 2;
						}
						else if (keyval == KEY_DEL)
						{
							keyflag = 2;
						}
						else if (keyval == KEYJING)
						{
							keyflag = 1;
						}
					}
				}

				break;

			case KEYJING:	//#�л����뷨
				keyflag = 1;
				break;

			case KEY_Enter:	//ȷ�Ϸ���
				return KEY_Enter;

			case KEY_UP:			//�������
				if (ChineseThinkFlag == 0)
				{
					if (pMove - receive > ALineNum)
					{
						for (i = 0; i < ALineNum; i++)
						{
							if (* (pMove - 1) > 0x80)  							//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�
							{
								pMove--;
								i++;

							}

							pMove--;
						}
					}
				}

				break;

			case KEY_DOWN:			//�������
				if (ChineseThinkFlag == 0)
				{
					for (i = 0; i < ALineNum && *pMove != 0; i++)
					{
						if (*pMove > 0x80)
						{
							pMove++;
							i++;
						}

						pMove++;
					}
				}

				break;

			case KEY_LEFT:			//�������
				if (pMove > receive)
				{
					if (* (pMove - 1) > 0x80) pMove--;				//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�

					pMove--;
				}

				break;

			case KEY_RIGHT:			//�������
				if (*pMove)
				{
					if (*pMove > 0x80) pMove++;

					pMove++;
				}

				break;

			case KEY_DEL:
				x = strlen ( (sc8*) receive);

				if (x != 0)
				{
					if (pMove > receive)
					{
						if (*pMove != 0)  						//������ַ���֮��ɾ��
						{
							if (* (pMove - 1) > 0x80)
							{
								pMove -= 2;
								my_strcpy_DeleteTailByte (pMove, pMove + 2);
							}
							else
							{
								pMove -= 1;
								my_strcpy_DeleteTailByte (pMove, pMove + 1);
							}
						}
						else
						{
							if (pMove > receive && * (pMove - 1) > 0x80)  							//delete a Chinese character
							{
								pMove--;
								*pMove = 0;
							}

							pMove--;
							*pMove = 0;
						}
					}
				}
				else
				{
					return KEY_LEFT;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1 || (keyflag == 2 && currentSrf != 4) )
		{
			if (keyflag == 1)
			{
				currentSrf = SwitchSrf (srfFlag, currentSrf);
			}

			DisplaySrfAndInput (currentSrf);
		}

		my_AccordPointInsertEdit (receive, pMove, 1, 2, &cursorx, &cursory);
		KeyIsResponse();
	}
}

static u8 my_abcReadCode (const u8 *BuffTheFirstAddr, u8 *pMove, char row)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.@1/?:;\'\"|\\{[}]=+-_)(*&^%$#!~`<>",
		"abc2",
		"def3",
		"ghi4",
		"jkl5",
		"mno6",
		"pqrs7",
		"tuv8",
		"wxyz9"
	};

	CalculateCursorOffset (SRF_abc);	//�������������뵽����ض��᷵��һ��asccii  ��
	x = pMove - BuffTheFirstAddr;

	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert (pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, row, row, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12);				//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}

static u8 my_ABCReadCode (const u8 *BuffTheFirstAddr, u8 *pMove, char row)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.@1/?:;\'\"|\\{[}]=+-_)(*&^%$#!~`<>",
		"ABC2",
		"DEF3",
		"GHI4",
		"JKL5",
		"MNO6",
		"PQRS7",
		"TUV8",
		"WXYZ9"
	};

	CalculateCursorOffset (SRF_ABC);	//�������������뵽����ض��᷵��һ��asccii	��
	x = pMove - BuffTheFirstAddr;
#ifdef DEBUG_PRINTF
	printf ("len=%d\n", x);
#endif
	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert ( (unsigned char*) pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, row, row, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12); 			//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}


char GetRejectReasonAndInput(void)
{
	char ReasonTable[15][MENU_COL]={0};
	char rejectNum=0;
	char *pMove;
	char keyval=0;
	char cursor_row=0;	
	char cursor_index=0;
	char i=0;
	char flashflag=0;
	char index=0;
	char keyflag=0;

	clear_lcd();
	GetRejectReason(ReasonTable,(char*)RejectReason,&rejectNum);
	if(rejectNum==0)
	{
		rejectNum=1;
	}
	
	cursor_index=rejectNum-1;	
	index=rejectNum-1;
	
	flashguangbiao_to_row (0, 0);
	if(rejectNum>4)
	{
		cursor_row=4;
	}
	else
	{
		cursor_index=4;
		cursor_row=index;
	}
	
	pMove = ReasonTable[index] + strlen(ReasonTable[index]);
	cursorX=6*strlen(ReasonTable[index]);
	if(index<=4)
	{
		cursorY=13*(index%5);
	}
	else
	{
		cursorY=13*4;
	}
	
	flashflag=1;

	while (1)
	{
		if(flashflag==1)
		{		
			flashflag=0;
			clear_lcd();
			for(i=0;i<5;i++)
			{
				text_out_to_row(i,(unsigned char*)ReasonTable[cursor_index+i-4]);
			}
		}
		else if(flashflag==2)
		{
			flashflag=0;
			clear_area_to_row(cursor_row,cursor_row);
			text_out_to_row(cursor_row,(unsigned char*)ReasonTable[cursor_index+cursor_row-4]);
		}
		else if(flashflag==3)
		{
			flashflag=0;
			clear_area_to_row(cursor_row+1,cursor_row+1);
			text_out_to_row(cursor_row+1,(unsigned char*)ReasonTable[cursor_index+cursor_row+1-4]);
		}
		else if(flashflag==4)
		{
			flashflag=0;
			clear_area_to_row(cursor_row-1,cursor_row-1);
			text_out_to_row(cursor_row-1,(unsigned char*)ReasonTable[cursor_index+cursor_row-1-4]);
		}
loop:		
		flightcursor();
		keyval = kmy_GetKeyValue();
		if (keyval == KEY_NONE) continue;
		KeyEventPost();
		switch (keyval)
		{
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
			case KEYXING:
				
				if(strlen(ReasonTable[index])<20)
				{
					pMove++;
					PostKey (keyval);
					if(keyflag==0)
					{
						keyval = my_abcReadCode ((u8*)ReasonTable[index], (u8*)pMove,cursor_row);
					}
					else 
					{
						keyval = my_ABCReadCode ((u8*)ReasonTable[index], (u8*)pMove,cursor_row);
					}
					
					if (keyval != KEY_NONE && keyval != KEYJING)
					{
						goto loop;
					}
				}
				
				break;
			case KEYJING:
				keyflag++;
				keyflag=keyflag%2;
				
				break;
			case KEY_UP:
				
				if(index>0)
				{
					index--;
				}
				if(cursor_row==0)
				{
					if(cursor_index>4)
					{
						cursor_index--;
						flashflag=1;
					}
				}
				if(cursor_row>0)
				{
					cursor_row--;
					cursorY -=13;
					flashflag=3;
				}
				if(cursorX>(6*strlen(ReasonTable[index])))
				{
					cursorX=6*strlen(ReasonTable[index]);
				}
				if(cursorX<6)
				{
					pMove = ReasonTable[index] ;
				}
				else
				{
					pMove = ReasonTable[index] + cursorX/6;
				}
				break;
				
			case KEY_DOWN:
				if(rejectNum<15)
				{
					if((index==rejectNum)||(rejectNum<=4&&index==rejectNum-1))
					{
						if(strlen(ReasonTable[index])>0)
						{
							rejectNum++;
						}
					}
					
				}
				
				if(cursor_row==4)
				{			
					if(cursor_index<rejectNum)
					{
						if((cursor_row==rejectNum-1)&&(strlen(ReasonTable[index])==0))
						{
						}
						else
						{
							cursor_index++; 							
							flashflag=1;
						}						
					}
				}
				if(index<rejectNum)
				{
					if((cursor_row==rejectNum-1)&&(strlen(ReasonTable[index])==0))
					{

					}
					else
					{
						index++;
					}
				}
				if(cursor_row<4)
				{
					if((cursor_row==rejectNum-1)&&(strlen(ReasonTable[index])==0))
					{

					}
					else
					{
						cursor_row++;					
						cursorY +=13;
					}
										
					flashflag=4;					
				}
				if(cursorX>(6*strlen(ReasonTable[index])))
				{
					cursorX=6*strlen(ReasonTable[index]);
				}
				if(cursorX<6)
				{
					pMove = ReasonTable[index] ;
				}
				else
				{
					pMove = ReasonTable[index] + cursorX/6;
				}

				break;
				
			case KEY_LEFT:
				if(cursorX>=6)
				{
					pMove--;
					flashflag=2;
					cursorX -=6;
				}
				
				break;
				
			case KEY_RIGHT: 			
				if(cursorX<6*strlen(ReasonTable[index]))
				{				
					pMove++;
					cursorX +=6;
					flashflag=2;
				}
				
				break;
				
			case KEY_Enter:
				memset(RejectReason,0,sizeof(RejectReason));
				for(i=0;i<rejectNum;i++)
				{
					if(strlen(ReasonTable[i])>0)
					{
						strcat((char*)RejectReason,ReasonTable[i]);
						strcat((char*)RejectReason,";");
					}
				}
				return keyval;
				
			case KEY_DEL:
				if(pMove!=ReasonTable[index])
				{
					if(cursorX>=6)
					{
						pMove--;
						flashflag=2;
						cursorX -=6;
						
						my_strcpy_DeleteTailByte ((unsigned char*)pMove,(unsigned char*)pMove+1);
					}
				}
				break;
				
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
				
			default:break;
		}

	}
	


}

	


void abcABC123PYWuBiArgDeInit (abcABC123PYWuBiArgument *arg, u8 *buff, u8 Size)
{
	(*arg).LocalTitle = "������";
	(*arg).OtherTitle = "Input";
	(*arg).receive = buff;
	(*arg).recSize = Size;
	(*arg).srfFlag = SRF_123 | SRF_ABC | SRF_abc;
	(*arg).DefaultSrf = SRF_123;
	(*arg).clearlcdflag = 1;
	(*arg).HaveoldFlag = 0;
}


u8 GetString_abcABC123PYWuBi2 (abcABC123PYWuBiArgument *arg)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_GetString_abcABC123PYWuBi ( (*arg).srfFlag, (*arg).DefaultSrf, (*arg).receive, (*arg).recSize, (*arg).HaveoldFlag) );
}


u8 GetString_abcABC123PYWuBi (const u8 *Title, u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	clear_lcd();

	if (Title != NULL) DrawTitle_to_row_Language2 (0, Title, Title);

	KeyIsResponse();

	return (_GetString_abcABC123PYWuBi (srfFlag, DefaultSrf, receive, recSize, HaveoldFlag) );
}
u8 GetString_123TimeInput (const u8 *Title, u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	clear_lcd();

	if (Title != NULL) DrawTitle_to_row_Language2 (0, Title, Title);

	KeyIsResponse();

	return (_GetString_123TimeInput (srfFlag, DefaultSrf, receive, recSize, HaveoldFlag) );
}

u8 GetString_abcABC123PYWuBi_Language2 (const u8 *LocalTitle, const u8 *OtherTitle, u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	clear_lcd();
	DrawTitle_to_row_Language2 (0, LocalTitle, OtherTitle);
	KeyIsResponse();

	return (_GetString_abcABC123PYWuBi (srfFlag, DefaultSrf, receive, recSize, HaveoldFlag) );
}


/*��x  λ�ÿ�ʼ��ʾ*/
static u8 _PassWordInput_XposStartDisplay (u8 *receive, u8 recSize, u8 xingflag, u8 DiplayRow, u8 Xpos, u8 argkeyval)
{
	u8 i;
	u8 inputSize;
	u8 displaybuff[22];
	u8 ClearFlag = 0;
	u8 keyval;

	inputSize = recSize > 21 ? 21 : recSize;
	memset (receive, 0, inputSize);
	i = 0;

	while (1)
	{
		if (argkeyval == KEY_NONE)
		{
			keyval = GetKeyValue();
		}
		else
		{
			keyval = argkeyval;
			argkeyval = KEY_NONE;
		}

		if (keyval == 0) continue;

		KeyEventPost();

		switch (keyval)
		{
			case KEY0:
				if (i < inputSize)
				{
					receive[i] = '0';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY1:
				if (i < inputSize)
				{
					receive[i] = '1';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY2:
				if (i < inputSize)
				{
					receive[i] = '2';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY3:
				if (i < inputSize)
				{
					receive[i] = '3';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY4:
				if (i < inputSize)
				{
					receive[i] = '4';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY5:
				if (i < inputSize)
				{
					receive[i] = '5';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY6:
				if (i < inputSize)
				{
					receive[i] = '6';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY7:
				if (i < inputSize)
				{
					receive[i] = '7';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY8:
				if (i < inputSize)
				{
					receive[i] = '8';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY9:
				if (i < inputSize)
				{
					receive[i] = '9';
					i++;
					receive[i] = 0;
				}

				break;

			case KEYXING:
				if (i < inputSize)
				{
					receive[i] = '.';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY_DEL:
				if (i > 0)
				{
					i--;
					receive[i] = 0;
					ClearFlag = 1;
				}

				break;

			case KEY_Enter:
				if (strlen ( (sc8*) receive) != 0)  	//��������ַ�Ϊ�գ����ð�ȷ�ϼ�����
				{
					KeyIsResponse();
					return KEY_Enter;
				}

				break;

			case KEY_ReturnPrevious:
				KeyIsResponse();
				return KEY_ReturnPrevious;

			case KEY_ReturnInitInterface:
			case KEY_WaitTimeout:
				KeyIsResponse();
				return KEY_ReturnInitInterface;
		}

		if (ClearFlag == 1)
		{
			ClearFlag = 0;
			clear_area (Xpos, DiplayRow * ALineContainDotLine, ALinePixNum - Xpos, ALineContainDotLine);
		}

		if (xingflag)
		{
			memset (displaybuff, '*', i);
			displaybuff[i] = 0;
			text_out_to_row_x (DiplayRow, Xpos, displaybuff);
		}
		else
		{
			text_out_to_row_x (DiplayRow, Xpos, receive);
		}

		KeyIsResponse();
	}
}

/*�м���ʾ*/
static u8 _PassWordInput_MiddledDisplay (u8 *receive, u8 recSize, u8 xingflag, u8 DiplayRow, u8 argkeyval)
{
	u8 i;
	u8 inputSize;
	u8 displaybuff[22];
	u8 ClearFlag = 0;
	u8 keyval;

	inputSize = recSize > 21 ? 21 : recSize;
	memset (receive, 0, inputSize);
	i = 0;

	while (1)
	{
		if (argkeyval == KEY_NONE)
		{
			keyval = GetKeyValue();
		}
		else
		{
			keyval = argkeyval;
			argkeyval = KEY_NONE;
		}

		if (keyval == 0) continue;

		KeyEventPost();

		switch (keyval)
		{
			case KEY0:
				if (i < inputSize)
				{
					receive[i] = '0';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY1:
				if (i < inputSize)
				{
					receive[i] = '1';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY2:
				if (i < inputSize)
				{
					receive[i] = '2';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY3:
				if (i < inputSize)
				{
					receive[i] = '3';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY4:
				if (i < inputSize)
				{
					receive[i] = '4';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY5:
				if (i < inputSize)
				{
					receive[i] = '5';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY6:
				if (i < inputSize)
				{
					receive[i] = '6';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY7:
				if (i < inputSize)
				{
					receive[i] = '7';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY8:
				if (i < inputSize)
				{
					receive[i] = '8';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY9:
				if (i < inputSize)
				{
					receive[i] = '9';
					i++;
					receive[i] = 0;
				}

				break;

			case KEYXING:
				if (i < inputSize)
				{
					receive[i] = '.';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY_DEL:
				if (i > 0)
				{
					i--;
					receive[i] = 0;
					ClearFlag = 1;
				}

				break;

			case KEY_Enter:
				if (strlen ( (sc8*) receive) != 0)  	//��������ַ�Ϊ�գ����ð�ȷ�ϼ�����
				{
					KeyIsResponse();
					return KEY_Enter;
				}

				break;

			case KEY_ReturnPrevious:
				KeyIsResponse();
				return KEY_ReturnPrevious;

			case KEY_ReturnInitInterface:
			case KEY_WaitTimeout:
				KeyIsResponse();
				return KEY_ReturnInitInterface;
		}

		if (ClearFlag == 1)
		{
			ClearFlag = 0;
			clear_area_to_row (DiplayRow, DiplayRow);
		}

		if (xingflag)
		{
			memset (displaybuff, '*', i);
			displaybuff[i] = 0;
			DrawTitle_to_row (DiplayRow, displaybuff);
		}
		else
		{
			DrawTitle_to_row (DiplayRow, receive);
		}

		KeyIsResponse();
	}
}



//Ĭ����������Ϊ�����������ַ���ʾ�ڵڶ��С�
//��������Ϊ"����������"Input Password"�������밴��
//����buff Ϊ�β�2�������ֽ�Ϊ�β�3����*  ��ʾ������ַ�
void PassWordArgDeInit (PasswordInputArgument *arg, u8 *buff, u8 Size)
{
	(*arg).clearlcdflag = 1;
	(*arg).DiplayRow = 1;
	(*arg).LocalTitle = "����������";
	(*arg).OtherTitle = "Input Password";
	(*arg).keyval = KEY_NONE;
	(*arg).receive = buff;
	(*arg).recSize = Size;
	(*arg).xingflag = 1;
}

/*motice:Title��receive��recSize  max value is 20*/
u8 PassWordInput (PasswordInputArgument *arg)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_PassWordInput_XposStartDisplay ( (*arg).receive, (*arg).recSize, (*arg).xingflag, (*arg).DiplayRow, 0, (*arg).keyval) );
}


u8 PassWordInput_MiddledDisplay (PasswordInputArgument *arg)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_PassWordInput_MiddledDisplay ( (*arg).receive, (*arg).recSize, (*arg).xingflag, (*arg).DiplayRow, (*arg).keyval) );
}

u8 PassWordInput_XposStartDisplay (PasswordInputArgument *arg, u8 Xpos)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_PassWordInput_XposStartDisplay ( (*arg).receive, (*arg).recSize, (*arg).xingflag, (*arg).DiplayRow, Xpos, (*arg).keyval) );
}


u8 PassWordInput2 (const u8 *Title, u8 *receive, u8 recSize, u8 xingflag, u8 clearlcdflag, u8 keyval, u8 DiplayRow)
{
	if (clearlcdflag) clear_lcd();

	if (Title != NULL) DrawTitle_to_row_Language2 (0, Title, Title);

	KeyIsResponse();

	return (_PassWordInput_XposStartDisplay (receive, recSize, xingflag, DiplayRow, 0, keyval) );
}



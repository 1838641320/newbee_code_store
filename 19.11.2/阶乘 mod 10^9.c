#include<stdio.h>
#define mod 1000000007
int main() {
	long long n;
	while(~scanf("%lld",&n)) {
		long long result=1,i=1,t=n/1000000;
		switch(t){
			case 1: result=641102369;break;
			case 2: result=578095319;break;
			case 3: result=5832229;break;
			case 4: result=259081142;break;
			case 5: result=974067448;break;
			case 6: result=316220877;break;
			case 7: result=690120224;break;
			case 8: result=251368199;break;
			case 9: result=980250487;break;
			case 10: result=682498929;break;
			case 11: result=134623568;break;
			case 12: result=95936601;break;
			case 13: result=933097914;break;
			case 14: result=167332441;break;
			case 15: result=598816162;break;
			case 16: result=336060741;break;
			case 17: result=248744620;break;
			case 18: result=626497524;break;
			case 19: result=288843364;break;
			case 20: result=491101308;break;
			case 21: result=245341950;break;
			case 22: result=565768255;break;
			case 23: result=246899319;break;
			case 24: result=968999;break;
			case 25: result=586350670;break;
			case 26: result=638587686;break;
			case 27: result=881746146;break;
			case 28: result=19426633;break;
			case 29: result=850500036;break;
			case 30: result=76479948;break;
			case 31: result=268124147;break;
			case 32: result=842267748;break;
			case 33: result=886294336;break;
			case 34: result=485348706;break;
			case 35: result=463847391;break;
			case 36: result=544075857;break;
			case 37: result=898187927;break;
			case 38: result=798967520;break;
			case 39: result=82926604;break;
			case 40: result=723816384;break;
			case 41: result=156530778;break;
			case 42: result=721996174;break;
			case 43: result=299085602;break;
			case 44: result=323604647;break;
			case 45: result=172827403;break;
			case 46: result=398699886;break;
			case 47: result=530389102;break;
			case 48: result=294587621;break;
			case 49: result=813805606;break;
			case 50: result=67347853;break;
			case 51: result=497478507;break;
			case 52: result=196447201;break;
			case 53: result=722054885;break;
			case 54: result=228338256;break;
			case 55: result=407719831;break;
			case 56: result=762479457;break;
			case 57: result=746536789;break;
			case 58: result=811667359;break;
			case 59: result=778773518;break;
			case 60: result=27368307;break;
			case 61: result=438371670;break;
			case 62: result=59469516;break;
			case 63: result=5974669;break;
			case 64: result=766196482;break;
			case 65: result=606322308;break;
			case 66: result=86609485;break;
			case 67: result=889750731;break;
			case 68: result=340941507;break;
			case 69: result=371263376;break;
			case 70: result=625544428;break;
			case 71: result=788878910;break;
			case 72: result=808412394;break;
			case 73: result=996952918;break;
			case 74: result=585237443;break;
			case 75: result=1669644;break;
			case 76: result=361786913;break;
			case 77: result=480748381;break;
			case 78: result=595143852;break;
			case 79: result=837229828;break;
			case 80: result=199888908;break;
			case 81: result=526807168;break;
			case 82: result=579691190;break;
			case 83: result=145404005;break;
			case 84: result=459188207;break;
			case 85: result=534491822;break;
			case 86: result=439729802;break;
			case 87: result=840398449;break;
			case 88: result=899297830;break;
			case 89: result=235861787;break;
			case 90: result=888050723;break;
			case 91: result=656116726;break;
			case 92: result=736550105;break;
			case 93: result=440902696;break;
			case 94: result=85990869;break;
			case 95: result=884343068;break;
			case 96: result=56305184;break;
			case 97: result=973478770;break;
			case 98: result=168891766;break;
			case 99: result=804805577;break;
			case 100: result=927880474;break;
			case 101: result=876297919;break;
			case 102: result=934814019;break;
			case 103: result=676405347;break;
			case 104: result=567277637;break;
			case 105: result=112249297;break;
			case 106: result=44930135;break;
			case 107: result=39417871;break;
			case 108: result=47401357;break;
			case 109: result=108819476;break;
			case 110: result=281863274;break;
			case 111: result=60168088;break;
			case 112: result=692636218;break;
			case 113: result=432775082;break;
			case 114: result=14235602;break;
			case 115: result=770511792;break;
			case 116: result=400295761;break;
			case 117: result=697066277;break;
			case 118: result=421835306;break;
			case 119: result=220108638;break;
			case 120: result=661224977;break;
			case 121: result=261799937;break;
			case 122: result=168203998;break;
			case 123: result=802214249;break;
			case 124: result=544064410;break;
			case 125: result=935080803;break;
			case 126: result=583967898;break;
			case 127: result=211768084;break;
			case 128: result=751231582;break;
			case 129: result=972424306;break;
			case 130: result=623534362;break;
			case 131: result=335160196;break;
			case 132: result=243276029;break;
			case 133: result=554749550;break;
			case 134: result=60050552;break;
			case 135: result=797848181;break;
			case 136: result=395891998;break;
			case 137: result=172428290;break;
			case 138: result=159554990;break;
			case 139: result=887420150;break;
			case 140: result=970055531;break;
			case 141: result=250388809;break;
			case 142: result=487998999;break;
			case 143: result=856259313;break;
			case 144: result=82104855;break;
			case 145: result=232253360;break;
			case 146: result=513365505;break;
			case 147: result=244109365;break;
			case 148: result=1559745;break;
			case 149: result=695345956;break;
			case 150: result=261384175;break;
			case 151: result=849009131;break;
			case 152: result=323214113;break;
			case 153: result=747664143;break;
			case 154: result=444090941;break;
			case 155: result=659224434;break;
			case 156: result=80729842;break;
			case 157: result=570033864;break;
			case 158: result=664989237;break;
			case 159: result=827348878;break;
			case 160: result=195888993;break;
			case 161: result=576798521;break;
			case 162: result=457882808;break;
			case 163: result=731551699;break;
			case 164: result=212938473;break;
			case 165: result=509096183;break;
			case 166: result=827544702;break;
			case 167: result=678320208;break;
			case 168: result=677711203;break;
			case 169: result=289752035;break;
			case 170: result=66404266;break;
			case 171: result=555972231;break;
			case 172: result=195290384;break;
			case 173: result=97136305;break;
			case 174: result=349551356;break;
			case 175: result=785113347;break;
			case 176: result=83489485;break;
			case 177: result=66247239;break;
			case 178: result=52167191;break;
			case 179: result=307390891;break;
			case 180: result=547665832;break;
			case 181: result=143066173;break;
			case 182: result=350016754;break;
			case 183: result=917404120;break;
			case 184: result=296269301;break;
			case 185: result=996122673;break;
			case 186: result=23015220;break;
			case 187: result=602139210;break;
			case 188: result=748566338;break;
			case 189: result=187348575;break;
			case 190: result=109838563;break;
			case 191: result=574053420;break;
			case 192: result=105574531;break;
			case 193: result=304173654;break;
			case 194: result=542432219;break;
			case 195: result=34538816;break;
			case 196: result=325636655;break;
			case 197: result=437843114;break;
			case 198: result=630621321;break;
			case 199: result=26853683;break;
			case 200: result=933245637;break;
			case 201: result=616368450;break;
			case 202: result=238971581;break;
			case 203: result=511371690;break;
			case 204: result=557301633;break;
			case 205: result=911398531;break;
			case 206: result=848952161;break;
			case 207: result=958992544;break;
			case 208: result=925152039;break;
			case 209: result=914456118;break;
			case 210: result=724691727;break;
			case 211: result=636817583;break;
			case 212: result=238087006;break;
			case 213: result=946237212;break;
			case 214: result=910291942;break;
			case 215: result=114985663;break;
			case 216: result=492237273;break;
			case 217: result=450387329;break;
			case 218: result=834860913;break;
			case 219: result=763017204;break;
			case 220: result=368925948;break;
			case 221: result=475812562;break;
			case 222: result=740594930;break;
			case 223: result=45060610;break;
			case 224: result=806047532;break;
			case 225: result=464456846;break;
			case 226: result=172115341;break;
			case 227: result=75307702;break;
			case 228: result=116261993;break;
			case 229: result=562519302;break;
			case 230: result=268838846;break;
			case 231: result=173784895;break;
			case 232: result=243624360;break;
			case 233: result=61570384;break;
			case 234: result=481661251;break;
			case 235: result=938269070;break;
			case 236: result=95182730;break;
			case 237: result=91068149;break;
			case 238: result=115435332;break;
			case 239: result=495022305;break;
			case 240: result=136026497;break;
			case 241: result=506496856;break;
			case 242: result=710729672;break;
			case 243: result=113570024;break;
			case 244: result=366384665;break;
			case 245: result=564758715;break;
			case 246: result=270239666;break;
			case 247: result=277118392;break;
			case 248: result=79874094;break;
			case 249: result=702807165;break;
			case 250: result=112390913;break;
			case 251: result=730341625;break;
			case 252: result=103056890;break;
			case 253: result=677948390;break;
			case 254: result=339464594;break;
			case 255: result=167240465;break;
			case 256: result=108312174;break;
			case 257: result=839079953;break;
			case 258: result=479334442;break;
			case 259: result=271788964;break;
			case 260: result=135498044;break;
			case 261: result=277717575;break;
			case 262: result=591048681;break;
			case 263: result=811637561;break;
			case 264: result=353339603;break;
			case 265: result=889410460;break;
			case 266: result=839849206;break;
			case 267: result=192345193;break;
			case 268: result=736265527;break;
			case 269: result=316439118;break;
			case 270: result=217544623;break;
			case 271: result=788132977;break;
			case 272: result=618898635;break;
			case 273: result=183011467;break;
			case 274: result=380858207;break;
			case 275: result=996097969;break;
			case 276: result=898554793;break;
			case 277: result=335353644;break;
			case 278: result=54062950;break;
			case 279: result=611251733;break;
			case 280: result=419363534;break;
			case 281: result=965429853;break;
			case 282: result=160398980;break;
			case 283: result=151319402;break;
			case 284: result=990918946;break;
			case 285: result=607730875;break;
			case 286: result=450718279;break;
			case 287: result=173539388;break;
			case 288: result=648991369;break;
			case 289: result=970937898;break;
			case 290: result=500780548;break;
			case 291: result=780122909;break;
			case 292: result=39052406;break;
			case 293: result=276894233;break;
			case 294: result=460373282;break;
			case 295: result=651081062;break;
			case 296: result=461415770;break;
			case 297: result=358700839;break;
			case 298: result=643638805;break;
			case 299: result=560006119;break;
			case 300: result=668123525;break;
			case 301: result=686692315;break;
			case 302: result=673464765;break;
			case 303: result=957633609;break;
			case 304: result=199866123;break;
			case 305: result=563432246;break;
			case 306: result=841799766;break;
			case 307: result=385330357;break;
			case 308: result=504962686;break;
			case 309: result=954061253;break;
			case 310: result=128487469;break;
			case 311: result=685707545;break;
			case 312: result=299172297;break;
			case 313: result=717975101;break;
			case 314: result=577786541;break;
			case 315: result=318951960;break;
			case 316: result=773206631;break;
			case 317: result=306832604;break;
			case 318: result=204355779;break;
			case 319: result=573592106;break;
			case 320: result=30977140;break;
			case 321: result=450398100;break;
			case 322: result=363172638;break;
			case 323: result=258379324;break;
			case 324: result=472935553;break;
			case 325: result=93940075;break;
			case 326: result=587220627;break;
			case 327: result=776264326;break;
			case 328: result=793270300;break;
			case 329: result=291733496;break;
			case 330: result=522049725;break;
			case 331: result=579995261;break;
			case 332: result=335416359;break;
			case 333: result=142946099;break;
			case 334: result=472012302;break;
			case 335: result=559947225;break;
			case 336: result=332139472;break;
			case 337: result=499377092;break;
			case 338: result=464599136;break;
			case 339: result=164752359;break;
			case 340: result=309058615;break;
			case 341: result=86117128;break;
			case 342: result=580204973;break;
			case 343: result=563781682;break;
			case 344: result=954840109;break;
			case 345: result=624577416;break;
			case 346: result=895609896;break;
			case 347: result=888287558;break;
			case 348: result=836813268;break;
			case 349: result=926036911;break;
			case 350: result=386027524;break;
			case 351: result=184419613;break;
			case 352: result=724205533;break;
			case 353: result=403351886;break;
			case 354: result=715247054;break;
			case 355: result=716986954;break;
			case 356: result=830567832;break;
			case 357: result=383388563;break;
			case 358: result=68409439;break;
			case 359: result=6734065;break;
			case 360: result=189239124;break;
			case 361: result=68322490;break;
			case 362: result=943653305;break;
			case 363: result=405755338;break;
			case 364: result=811056092;break;
			case 365: result=179518046;break;
			case 366: result=825132993;break;
			case 367: result=343807435;break;
			case 368: result=985084650;break;
			case 369: result=868553027;break;
			case 370: result=148528617;break;
			case 371: result=160684257;break;
			case 372: result=882148737;break;
			case 373: result=591915968;break;
			case 374: result=701445829;break;
			case 375: result=529726489;break;
			case 376: result=302177126;break;
			case 377: result=974886682;break;
			case 378: result=241107368;break;
			case 379: result=798830099;break;
			case 380: result=940567523;break;
			case 381: result=11633075;break;
			case 382: result=325334066;break;
			case 383: result=346091869;break;
			case 384: result=115312728;break;
			case 385: result=473718967;break;
			case 386: result=218129285;break;
			case 387: result=878471898;break;
			case 388: result=180002392;break;
			case 389: result=699739374;break;
			case 390: result=917084264;break;
			case 391: result=856859395;break;
			case 392: result=435327356;break;
			case 393: result=808651347;break;
			case 394: result=421623838;break;
			case 395: result=105419548;break;
			case 396: result=59883031;break;
			case 397: result=322487421;break;
			case 398: result=79716267;break;
			case 399: result=715317963;break;
			case 400: result=429277690;break;
			case 401: result=398078032;break;
			case 402: result=316486674;break;
			case 403: result=384843585;break;
			case 404: result=940338439;break;
			case 405: result=937409008;break;
			case 406: result=940524812;break;
			case 407: result=947549662;break;
			case 408: result=833550543;break;
			case 409: result=593524514;break;
			case 410: result=996164327;break;
			case 411: result=987314628;break;
			case 412: result=697611981;break;
			case 413: result=636177449;break;
			case 414: result=274192146;break;
			case 415: result=418537348;break;
			case 416: result=925347821;break;
			case 417: result=952831975;break;
			case 418: result=893732627;break;
			case 419: result=1277567;break;
			case 420: result=358655417;break;
			case 421: result=141866945;break;
			case 422: result=581830879;break;
			case 423: result=987597705;break;
			case 424: result=347046911;break;
			case 425: result=775305697;break;
			case 426: result=125354499;break;
			case 427: result=951540811;break;
			case 428: result=247662371;break;
			case 429: result=343043237;break;
			case 430: result=568392357;break;
			case 431: result=997474832;break;
			case 432: result=209244402;break;
			case 433: result=380480118;break;
			case 434: result=149586983;break;
			case 435: result=392838702;break;
			case 436: result=309134554;break;
			case 437: result=990779998;break;
			case 438: result=263053337;break;
			case 439: result=325362513;break;
			case 440: result=780072518;break;
			case 441: result=551028176;break;
			case 442: result=990826116;break;
			case 443: result=989944961;break;
			case 444: result=155569943;break;
			case 445: result=596737944;break;
			case 446: result=711553356;break;
			case 447: result=268844715;break;
			case 448: result=451373308;break;
			case 449: result=379404150;break;
			case 450: result=462639908;break;
			case 451: result=961812918;break;
			case 452: result=654611901;break;
			case 453: result=382776490;break;
			case 454: result=41815820;break;
			case 455: result=843321396;break;
			case 456: result=675258797;break;
			case 457: result=845583555;break;
			case 458: result=934281721;break;
			case 459: result=741114145;break;
			case 460: result=275105629;break;
			case 461: result=666247477;break;
			case 462: result=325912072;break;
			case 463: result=526131620;break;
			case 464: result=252551589;break;
			case 465: result=432030917;break;
			case 466: result=554917439;break;
			case 467: result=818036959;break;
			case 468: result=754363835;break;
			case 469: result=795190182;break;
			case 470: result=909210595;break;
			case 471: result=278704903;break;
			case 472: result=719566487;break;
			case 473: result=628514947;break;
			case 474: result=424989675;break;
			case 475: result=321685608;break;
			case 476: result=50590510;break;
			case 477: result=832069712;break;
			case 478: result=198768464;break;
			case 479: result=702004730;break;
			case 480: result=99199382;break;
			case 481: result=707469729;break;
			case 482: result=747407118;break;
			case 483: result=302020341;break;
			case 484: result=497196934;break;
			case 485: result=5003231;break;
			case 486: result=726997875;break;
			case 487: result=382617671;break;
			case 488: result=296229203;break;
			case 489: result=183888367;break;
			case 490: result=703397904;break;
			case 491: result=552133875;break;
			case 492: result=732868367;break;
			case 493: result=350095207;break;
			case 494: result=26031303;break;
			case 495: result=863250534;break;
			case 496: result=216665960;break;
			case 497: result=561745549;break;
			case 498: result=352946234;break;
			case 499: result=784139777;break;
			case 500: result=733333339;break;
			case 501: result=503105966;break;
			case 502: result=459878625;break;
			case 503: result=803187381;break;
			case 504: result=16634739;break;
			case 505: result=180898306;break;
			case 506: result=68718097;break;
			case 507: result=985594252;break;
			case 508: result=404206040;break;
			case 509: result=749724532;break;
			case 510: result=97830135;break;
			case 511: result=611751357;break;
			case 512: result=31131935;break;
			case 513: result=662741752;break;
			case 514: result=864326453;break;
			case 515: result=864869025;break;
			case 516: result=167831173;break;
			case 517: result=559214642;break;
			case 518: result=718498895;break;
			case 519: result=91352335;break;
			case 520: result=608823837;break;
			case 521: result=473379392;break;
			case 522: result=385388084;break;
			case 523: result=152267158;break;
			case 524: result=681756977;break;
			case 525: result=46819124;break;
			case 526: result=313132653;break;
			case 527: result=56547945;break;
			case 528: result=442795120;break;
			case 529: result=796616594;break;
			case 530: result=256141983;break;
			case 531: result=152028387;break;
			case 532: result=636578562;break;
			case 533: result=385377759;break;
			case 534: result=553033642;break;
			case 535: result=491415383;break;
			case 536: result=919273670;break;
			case 537: result=996049638;break;
			case 538: result=326686486;break;
			case 539: result=160150665;break;
			case 540: result=141827977;break;
			case 541: result=540818053;break;
			case 542: result=693305776;break;
			case 543: result=593938674;break;
			case 544: result=186576440;break;
			case 545: result=688809790;break;
			case 546: result=565456578;break;
			case 547: result=749296077;break;
			case 548: result=519397500;break;
			case 549: result=551096742;break;
			case 550: result=696628828;break;
			case 551: result=775025061;break;
			case 552: result=370732451;break;
			case 553: result=164246193;break;
			case 554: result=915265013;break;
			case 555: result=457469634;break;
			case 556: result=923043932;break;
			case 557: result=912368644;break;
			case 558: result=777901604;break;
			case 559: result=464118005;break;
			case 560: result=637939935;break;
			case 561: result=956856710;break;
			case 562: result=490676632;break;
			case 563: result=453019482;break;
			case 564: result=462528877;break;
			case 565: result=502297454;break;
			case 566: result=798895521;break;
			case 567: result=100498586;break;
			case 568: result=699767918;break;
			case 569: result=849974789;break;
			case 570: result=811575797;break;
			case 571: result=438952959;break;
			case 572: result=606870929;break;
			case 573: result=907720182;break;
			case 574: result=179111720;break;
			case 575: result=48053248;break;
			case 576: result=508038818;break;
			case 577: result=811944661;break;
			case 578: result=752550134;break;
			case 579: result=401382061;break;
			case 580: result=848924691;break;
			case 581: result=764368449;break;
			case 582: result=34629406;break;
			case 583: result=529840945;break;
			case 584: result=435904287;break;
			case 585: result=26011548;break;
			case 586: result=208184231;break;
			case 587: result=446477394;break;
			case 588: result=206330671;break;
			case 589: result=366033520;break;
			case 590: result=131772368;break;
			case 591: result=185646898;break;
			case 592: result=648711554;break;
			case 593: result=472759660;break;
			case 594: result=523696723;break;
			case 595: result=271198437;break;
			case 596: result=25058942;break;
			case 597: result=859369491;break;
			case 598: result=817928963;break;
			case 599: result=330711333;break;
			case 600: result=724464507;break;
			case 601: result=437605233;break;
			case 602: result=701453022;break;
			case 603: result=626663115;break;
			case 604: result=281230685;break;
			case 605: result=510650790;break;
			case 606: result=596949867;break;
			case 607: result=295726547;break;
			case 608: result=303076380;break;
			case 609: result=465070856;break;
			case 610: result=272814771;break;
			case 611: result=538771609;break;
			case 612: result=48824684;break;
			case 613: result=951279549;break;
			case 614: result=939889684;break;
			case 615: result=564188856;break;
			case 616: result=48527183;break;
			case 617: result=201307702;break;
			case 618: result=484458461;break;
			case 619: result=861754542;break;
			case 620: result=326159309;break;
			case 621: result=181594759;break;
			case 622: result=668422905;break;
			case 623: result=286273596;break;
			case 624: result=965656187;break;
			case 625: result=44135644;break;
			case 626: result=359960756;break;
			case 627: result=936229527;break;
			case 628: result=407934361;break;
			case 629: result=267193060;break;
			case 630: result=456152084;break;
			case 631: result=459116722;break;
			case 632: result=124804049;break;
			case 633: result=262322489;break;
			case 634: result=920251227;break;
			case 635: result=816929577;break;
			case 636: result=483924582;break;
			case 637: result=151834896;break;
			case 638: result=167087470;break;
			case 639: result=490222511;break;
			case 640: result=903466878;break;
			case 641: result=361583925;break;
			case 642: result=368114731;break;
			case 643: result=339383292;break;
			case 644: result=388728584;break;
			case 645: result=218107212;break;
			case 646: result=249153339;break;
			case 647: result=909458706;break;
			case 648: result=322908524;break;
			case 649: result=202649964;break;
			case 650: result=92255682;break;
			case 651: result=573074791;break;
			case 652: result=15570863;break;
			case 653: result=94331513;break;
			case 654: result=744158074;break;
			case 655: result=196345098;break;
			case 656: result=334326205;break;
			case 657: result=9416035;break;
			case 658: result=98349682;break;
			case 659: result=882121662;break;
			case 660: result=769795511;break;
			case 661: result=231988936;break;
			case 662: result=888146074;break;
			case 663: result=137603545;break;
			case 664: result=582627184;break;
			case 665: result=407518072;break;
			case 666: result=919419361;break;
			case 667: result=909433461;break;
			case 668: result=986708498;break;
			case 669: result=310317874;break;
			case 670: result=373745190;break;
			case 671: result=263645931;break;
			case 672: result=256853930;break;
			case 673: result=876379959;break;
			case 674: result=702823274;break;
			case 675: result=147050765;break;
			case 676: result=308186532;break;
			case 677: result=175504139;break;
			case 678: result=180350107;break;
			case 679: result=797736554;break;
			case 680: result=606241871;break;
			case 681: result=384547635;break;
			case 682: result=273712630;break;
			case 683: result=586444655;break;
			case 684: result=682189174;break;
			case 685: result=666493603;break;
			case 686: result=946867127;break;
			case 687: result=819114541;break;
			case 688: result=502371023;break;
			case 689: result=261970285;break;
			case 690: result=825871994;break;
			case 691: result=126925175;break;
			case 692: result=701506133;break;
			case 693: result=314738056;break;
			case 694: result=341779962;break;
			case 695: result=561011609;break;
			case 696: result=815463367;break;
			case 697: result=46765164;break;
			case 698: result=49187570;break;
			case 699: result=188054995;break;
			case 700: result=957939114;break;
			case 701: result=64814326;break;
			case 702: result=933376898;break;
			case 703: result=329837066;break;
			case 704: result=338121343;break;
			case 705: result=765215899;break;
			case 706: result=869630152;break;
			case 707: result=978119194;break;
			case 708: result=632627667;break;
			case 709: result=975266085;break;
			case 710: result=435887178;break;
			case 711: result=282092463;break;
			case 712: result=129621197;break;
			case 713: result=758245605;break;
			case 714: result=827722926;break;
			case 715: result=201339230;break;
			case 716: result=918513230;break;
			case 717: result=322096036;break;
			case 718: result=547838438;break;
			case 719: result=985546115;break;
			case 720: result=852304035;break;
			case 721: result=593090119;break;
			case 722: result=689189630;break;
			case 723: result=555842733;break;
			case 724: result=567033437;break;
			case 725: result=469928208;break;
			case 726: result=212842957;break;
			case 727: result=117842065;break;
			case 728: result=404149413;break;
			case 729: result=155133422;break;
			case 730: result=663307737;break;
			case 731: result=208761293;break;
			case 732: result=206282795;break;
			case 733: result=717946122;break;
			case 734: result=488906585;break;
			case 735: result=414236650;break;
			case 736: result=280700600;break;
			case 737: result=962670136;break;
			case 738: result=534279149;break;
			case 739: result=214569244;break;
			case 740: result=375297772;break;
			case 741: result=811053196;break;
			case 742: result=922377372;break;
			case 743: result=289594327;break;
			case 744: result=219932130;break;
			case 745: result=211487466;break;
			case 746: result=701050258;break;
			case 747: result=398782410;break;
			case 748: result=863002719;break;
			case 749: result=27236531;break;
			case 750: result=217598709;break;
			case 751: result=375472836;break;
			case 752: result=810551911;break;
			case 753: result=178598958;break;
			case 754: result=247844667;break;
			case 755: result=676526196;break;
			case 756: result=812283640;break;
			case 757: result=863066876;break;
			case 758: result=857241854;break;
			case 759: result=113917835;break;
			case 760: result=624148346;break;
			case 761: result=726089763;break;
			case 762: result=564827277;break;
			case 763: result=826300950;break;
			case 764: result=478982047;break;
			case 765: result=439411911;break;
			case 766: result=454039189;break;
			case 767: result=633292726;break;
			case 768: result=48562889;break;
			case 769: result=802100365;break;
			case 770: result=671734977;break;
			case 771: result=945204804;break;
			case 772: result=508831870;break;
			case 773: result=398781902;break;
			case 774: result=897162044;break;
			case 775: result=644050694;break;
			case 776: result=892168027;break;
			case 777: result=828883117;break;
			case 778: result=277714559;break;
			case 779: result=713448377;break;
			case 780: result=624500515;break;
			case 781: result=590098114;break;
			case 782: result=808691930;break;
			case 783: result=514359662;break;
			case 784: result=895205045;break;
			case 785: result=715264908;break;
			case 786: result=628829100;break;
			case 787: result=484492064;break;
			case 788: result=919717789;break;
			case 789: result=513196123;break;
			case 790: result=748510389;break;
			case 791: result=403652653;break;
			case 792: result=574455974;break;
			case 793: result=77123823;break;
			case 794: result=172096141;break;
			case 795: result=819801784;break;
			case 796: result=581418893;break;
			case 797: result=15655126;break;
			case 798: result=15391652;break;
			case 799: result=875641535;break;
			case 800: result=203191898;break;
			case 801: result=264582598;break;
			case 802: result=880691101;break;
			case 803: result=907800444;break;
			case 804: result=986598821;break;
			case 805: result=340030191;break;
			case 806: result=264688936;break;
			case 807: result=369832433;break;
			case 808: result=785804644;break;
			case 809: result=842065079;break;
			case 810: result=423951674;break;
			case 811: result=663560047;break;
			case 812: result=696623384;break;
			case 813: result=496709826;break;
			case 814: result=161960209;break;
			case 815: result=331910086;break;
			case 816: result=541120825;break;
			case 817: result=951524114;break;
			case 818: result=841656666;break;
			case 819: result=162683802;break;
			case 820: result=629786193;break;
			case 821: result=190395535;break;
			case 822: result=269571439;break;
			case 823: result=832671304;break;
			case 824: result=76770272;break;
			case 825: result=341080135;break;
			case 826: result=421943723;break;
			case 827: result=494210290;break;
			case 828: result=751040886;break;
			case 829: result=317076664;break;
			case 830: result=672850561;break;
			case 831: result=72482816;break;
			case 832: result=493689107;break;
			case 833: result=135625240;break;
			case 834: result=100228913;break;
			case 835: result=684748812;break;
			case 836: result=639655136;break;
			case 837: result=906233141;break;
			case 838: result=929893103;break;
			case 839: result=277813439;break;
			case 840: result=814362881;break;
			case 841: result=562608724;break;
			case 842: result=406024012;break;
			case 843: result=885537778;break;
			case 844: result=10065330;break;
			case 845: result=60625018;break;
			case 846: result=983737173;break;
			case 847: result=60517502;break;
			case 848: result=551060742;break;
			case 849: result=804930491;break;
			case 850: result=823845496;break;
			case 851: result=727416538;break;
			case 852: result=946421040;break;
			case 853: result=678171399;break;
			case 854: result=842203531;break;
			case 855: result=175638827;break;
			case 856: result=894247956;break;
			case 857: result=538609927;break;
			case 858: result=885362182;break;
			case 859: result=946464959;break;
			case 860: result=116667533;break;
			case 861: result=749816133;break;
			case 862: result=241427979;break;
			case 863: result=871117927;break;
			case 864: result=281804989;break;
			case 865: result=163928347;break;
			case 866: result=563796647;break;
			case 867: result=640266394;break;
			case 868: result=774625892;break;
			case 869: result=59342705;break;
			case 870: result=256473217;break;
			case 871: result=674115061;break;
			case 872: result=918860977;break;
			case 873: result=322633051;break;
			case 874: result=753513874;break;
			case 875: result=393556719;break;
			case 876: result=304644842;break;
			case 877: result=767372800;break;
			case 878: result=161362528;break;
			case 879: result=754787150;break;
			case 880: result=627655552;break;
			case 881: result=677395736;break;
			case 882: result=799289297;break;
			case 883: result=846650652;break;
			case 884: result=816701166;break;
			case 885: result=687265514;break;
			case 886: result=787113234;break;
			case 887: result=358757251;break;
			case 888: result=701220427;break;
			case 889: result=607715125;break;
			case 890: result=245795606;break;
			case 891: result=600624983;break;
			case 892: result=10475577;break;
			case 893: result=728620948;break;
			case 894: result=759404319;break;
			case 895: result=36292292;break;
			case 896: result=491466901;break;
			case 897: result=22556579;break;
			case 898: result=114495791;break;
			case 899: result=647630109;break;
			case 900: result=586445753;break;
			case 901: result=482254337;break;
			case 902: result=718623833;break;
			case 903: result=763514207;break;
			case 904: result=66547751;break;
			case 905: result=953634340;break;
			case 906: result=351472920;break;
			case 907: result=308474522;break;
			case 908: result=494166907;break;
			case 909: result=634359666;break;
			case 910: result=172114298;break;
			case 911: result=865440961;break;
			case 912: result=364380585;break;
			case 913: result=921648059;break;
			case 914: result=965683742;break;
			case 915: result=260466949;break;
			case 916: result=117483873;break;
			case 917: result=962540888;break;
			case 918: result=237120480;break;
			case 919: result=620531822;break;
			case 920: result=193781724;break;
			case 921: result=213092254;break;
			case 922: result=107141741;break;
			case 923: result=602742426;break;
			case 924: result=793307102;break;
			case 925: result=756154604;break;
			case 926: result=236455213;break;
			case 927: result=362928234;break;
			case 928: result=14162538;break;
			case 929: result=753042874;break;
			case 930: result=778983779;break;
			case 931: result=25977209;break;
			case 932: result=49389215;break;
			case 933: result=698308420;break;
			case 934: result=859637374;break;
			case 935: result=49031023;break;
			case 936: result=713258160;break;
			case 937: result=737331920;break;
			case 938: result=923333660;break;
			case 939: result=804861409;break;
			case 940: result=83868974;break;
			case 941: result=682873215;break;
			case 942: result=217298111;break;
			case 943: result=883278906;break;
			case 944: result=176966527;break;
			case 945: result=954913;break;
			case 946: result=105359006;break;
			case 947: result=390019735;break;
			case 948: result=10430738;break;
			case 949: result=706334445;break;
			case 950: result=315103615;break;
			case 951: result=567473423;break;
			case 952: result=708233401;break;
			case 953: result=48160594;break;
			case 954: result=946149627;break;
			case 955: result=346966053;break;
			case 956: result=281329488;break;
			case 957: result=462880311;break;
			case 958: result=31503476;break;
			case 959: result=185438078;break;
			case 960: result=965785236;break;
			case 961: result=992656683;break;
			case 962: result=916291845;break;
			case 963: result=881482632;break;
			case 964: result=899946391;break;
			case 965: result=321900901;break;
			case 966: result=512634493;break;
			case 967: result=303338827;break;
			case 968: result=121000338;break;
			case 969: result=967284733;break;
			case 970: result=492741665;break;
			case 971: result=152233223;break;
			case 972: result=165393390;break;
			case 973: result=680128316;break;
			case 974: result=917041303;break;
			case 975: result=532702135;break;
			case 976: result=741626808;break;
			case 977: result=496442755;break;
			case 978: result=536841269;break;
			case 979: result=131384366;break;
			case 980: result=377329025;break;
			case 981: result=301196854;break;
			case 982: result=859917803;break;
			case 983: result=676511002;break;
			case 984: result=373451745;break;
			case 985: result=847645126;break;
			case 986: result=823495900;break;
			case 987: result=576368335;break;
			case 988: result=73146164;break;
			case 989: result=954958912;break;
			case 990: result=847549272;break;
			case 991: result=241289571;break;
			case 992: result=646654592;break;
			case 993: result=216046746;break;
			case 994: result=205951465;break;
			case 995: result=3258987;break;
			case 996: result=780882948;break;
			case 997: result=822439091;break;
			case 998: result=598245292;break;
			case 999: result=869544707;break;
			case 1000: result=698611116;break;
		}
		i=t*1000000+1;
		for(; i<=n; i++) {
			result=(result*i)%mod;
		}
		printf("%lld\n",result);
	}
}

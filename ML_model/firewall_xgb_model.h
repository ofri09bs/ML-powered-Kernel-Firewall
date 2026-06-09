#ifndef FIREWALL_XGB_MODEL_H
#define FIREWALL_XGB_MODEL_H

static __always_inline long long calc_model_score(long long *input) {
    long long var0 = 0;
    long long var1 = 0, var2 = 0, var3 = 0, var4 = 0, var5 = 0, var6 = 0, var7 = 0, var8 = 0, var9 = 0;
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 31) {
                if (input[6] < 1) {
                    if (input[1] < 12) {
                        var0 = -163291;
                    } else {
                        var0 = 72407;
                    }
                } else {
                    if (input[0] < 4) {
                        var0 = 39214;
                    } else {
                        var0 = -166072;
                    }
                }
            } else {
                if (input[8] < 5346653000) {
                    if (input[3] < 3525) {
                        var0 = 169700;
                    } else {
                        var0 = 35453;
                    }
                } else {
                    if (input[3] < 225) {
                        var0 = 196821;
                    } else {
                        var0 = -142362;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 11621) {
                        var0 = 107692;
                    } else {
                        var0 = -193112;
                    }
                } else {
                    var0 = 197047;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 532413000) {
                        var0 = 184000;
                    } else {
                        var0 = -41025;
                    }
                } else {
                    if (input[3] < 11595) {
                        var0 = 197711;
                    } else {
                        var0 = 26865;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var0 = 199995;
            } else {
                if (input[2] < 191) {
                    var0 = -190243;
                } else {
                    var0 = 198632;
                }
            }
        } else {
            if (input[1] < 785) {
                var0 = -196412;
            } else {
                var0 = 184615;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 31) {
                if (input[6] < 1) {
                    if (input[3] < 6) {
                        var1 = 97020;
                    } else {
                        var1 = -145839;
                    }
                } else {
                    if (input[0] < 4) {
                        var1 = 35307;
                    } else {
                        var1 = -150538;
                    }
                }
            } else {
                if (input[8] < 5680947000) {
                    if (input[3] < 37) {
                        var1 = 99291;
                    } else {
                        var1 = 159393;
                    }
                } else {
                    if (input[3] < 225) {
                        var1 = 178929;
                    } else {
                        var1 = -136091;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 9747) {
                        var1 = 181179;
                    } else {
                        var1 = -175424;
                    }
                } else {
                    var1 = 179401;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 532413000) {
                        var1 = 167740;
                    } else {
                        var1 = -37148;
                    }
                } else {
                    if (input[3] < 11595) {
                        var1 = 179764;
                    } else {
                        var1 = 24343;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var1 = 181869;
            } else {
                if (input[2] < 191) {
                    var1 = -173687;
                } else {
                    var1 = 180728;
                }
            }
        } else {
            if (input[1] < 785) {
                var1 = -178868;
            } else {
                var1 = 168943;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 10000) {
                        var2 = -122937;
                    } else {
                        var2 = 64902;
                    }
                } else {
                    if (input[8] < 1516000) {
                        var2 = -171807;
                    } else {
                        var2 = 59482;
                    }
                }
            } else {
                if (input[3] < 23) {
                    if (input[1] < 24) {
                        var2 = 127092;
                    } else {
                        var2 = -137140;
                    }
                } else {
                    if (input[8] < 5346653000) {
                        var2 = 140262;
                    } else {
                        var2 = -51033;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[4] < 1) {
                    if (input[1] < 9747) {
                        var2 = 166145;
                    } else {
                        var2 = -162022;
                    }
                } else {
                    var2 = 166052;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 532413000) {
                        var2 = 162940;
                    } else {
                        var2 = -60226;
                    }
                } else {
                    if (input[3] < 11595) {
                        var2 = 166215;
                    } else {
                        var2 = 22065;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var2 = 168255;
            } else {
                if (input[2] < 191) {
                    var2 = -160963;
                } else {
                    var2 = 167236;
                }
            }
        } else {
            if (input[1] < 785) {
                var2 = -165577;
            } else {
                var2 = 156744;
            }
        }
    }
    
    if (input[2] < 6) {
        if (input[0] < 17) {
            if (input[1] < 11621) {
                if (input[1] < 16) {
                    if (input[3] < 6) {
                        var3 = -5697;
                    } else {
                        var3 = -147046;
                    }
                } else {
                    if (input[5] < 1) {
                        var3 = 130914;
                    } else {
                        var3 = -84926;
                    }
                }
            } else {
                if (input[4] < 1) {
                    if (input[1] < 15482) {
                        var3 = -152561;
                    } else {
                        var3 = 199453;
                    }
                } else {
                    var3 = 156529;
                }
            }
        } else {
            if (input[3] < 242) {
                if (input[0] < 25) {
                    if (input[6] < 1) {
                        var3 = -221424;
                    } else {
                        var3 = 192847;
                    }
                } else {
                    if (input[1] < 14) {
                        var3 = 196416;
                    } else {
                        var3 = 161371;
                    }
                }
            } else {
                if (input[8] < 5346653000) {
                    if (input[3] < 1061) {
                        var3 = 74621;
                    } else {
                        var3 = 156843;
                    }
                } else {
                    if (input[1] < 11890) {
                        var3 = 71923;
                    } else {
                        var3 = -155930;
                    }
                }
            }
        }
    } else {
        if (input[8] < 308318800) {
            if (input[1] < 24) {
                if (input[3] < 11) {
                    if (input[8] < 6000) {
                        var3 = 182115;
                    } else {
                        var3 = 173213;
                    }
                } else {
                    if (input[3] < 14) {
                        var3 = -150680;
                    } else {
                        var3 = 158082;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[8] < 3332333) {
                        var3 = 217579;
                    } else {
                        var3 = -123623;
                    }
                } else {
                    if (input[3] < 517) {
                        var3 = 158010;
                    } else {
                        var3 = 124249;
                    }
                }
            }
        } else {
            if (input[1] < 31) {
                if (input[0] < 4) {
                    if (input[0] < 3) {
                        var3 = 173561;
                    } else {
                        var3 = 26307;
                    }
                } else {
                    if (input[8] < 15700000000) {
                        var3 = -163138;
                    } else {
                        var3 = -43182;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[8] < 2114104400) {
                        var3 = 43491;
                    } else {
                        var3 = 113183;
                    }
                } else {
                    if (input[2] < 141) {
                        var3 = 160969;
                    } else {
                        var3 = -117457;
                    }
                }
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 10000) {
                        var4 = -110105;
                    } else {
                        var4 = 58985;
                    }
                } else {
                    if (input[8] < 999000) {
                        var4 = -151651;
                    } else {
                        var4 = 61828;
                    }
                }
            } else {
                if (input[1] < 31) {
                    if (input[1] < 24) {
                        var4 = 107391;
                    } else {
                        var4 = -138831;
                    }
                } else {
                    if (input[8] < 5680947000) {
                        var4 = 119967;
                    } else {
                        var4 = -49276;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 9747) {
                        var4 = 147176;
                    } else {
                        var4 = -142826;
                    }
                } else {
                    var4 = 147971;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 532413000) {
                        var4 = 135571;
                    } else {
                        var4 = -42397;
                    }
                } else {
                    if (input[3] < 11595) {
                        var4 = 147121;
                    } else {
                        var4 = 5437;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var4 = 149244;
            } else {
                if (input[2] < 191) {
                    var4 = -144409;
                } else {
                    var4 = 149377;
                }
            }
        } else {
            if (input[1] < 785) {
                var4 = -148750;
            } else {
                var4 = 149048;
            }
        }
    }
    
    if (input[2] < 6) {
        if (input[0] < 17) {
            if (input[1] < 11621) {
                if (input[1] < 16) {
                    if (input[3] < 6) {
                        var5 = -4677;
                    } else {
                        var5 = -131045;
                    }
                } else {
                    if (input[5] < 1) {
                        var5 = 114069;
                    } else {
                        var5 = -84282;
                    }
                }
            } else {
                if (input[4] < 1) {
                    if (input[0] < 16) {
                        var5 = -137938;
                    } else {
                        var5 = -104469;
                    }
                } else {
                    var5 = 141313;
                }
            }
        } else {
            if (input[3] < 242) {
                if (input[0] < 25) {
                    if (input[6] < 1) {
                        var5 = -207441;
                    } else {
                        var5 = 170352;
                    }
                } else {
                    if (input[1] < 14) {
                        var5 = 173830;
                    } else {
                        var5 = 145816;
                    }
                }
            } else {
                if (input[8] < 5346653000) {
                    if (input[3] < 1061) {
                        var5 = 58722;
                    } else {
                        var5 = 141431;
                    }
                } else {
                    if (input[1] < 11890) {
                        var5 = 68101;
                    } else {
                        var5 = -140657;
                    }
                }
            }
        }
    } else {
        if (input[8] < 308318800) {
            if (input[8] < 136555000) {
                if (input[1] < 24) {
                    if (input[3] < 11) {
                        var5 = 154227;
                    } else {
                        var5 = 48051;
                    }
                } else {
                    if (input[3] < 14) {
                        var5 = -11567;
                    } else {
                        var5 = 142542;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[0] < 4) {
                        var5 = 160486;
                    } else {
                        var5 = -121918;
                    }
                } else {
                    var5 = 142897;
                }
            }
        } else {
            if (input[1] < 31) {
                if (input[0] < 4) {
                    if (input[0] < 3) {
                        var5 = 153191;
                    } else {
                        var5 = 13733;
                    }
                } else {
                    if (input[8] < 15700000000) {
                        var5 = -146548;
                    } else {
                        var5 = -29768;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[8] < 2114104400) {
                        var5 = 27778;
                    } else {
                        var5 = 94566;
                    }
                } else {
                    if (input[2] < 141) {
                        var5 = 145690;
                    } else {
                        var5 = -103231;
                    }
                }
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 6000) {
                        var6 = -101030;
                    } else {
                        var6 = 52864;
                    }
                } else {
                    if (input[8] < 999000) {
                        var6 = -138276;
                    } else {
                        var6 = 69136;
                    }
                }
            } else {
                if (input[8] < 181674860) {
                    if (input[5] < 1) {
                        var6 = 119801;
                    } else {
                        var6 = -18337;
                    }
                } else {
                    if (input[3] < 37) {
                        var6 = -77260;
                    } else {
                        var6 = 95029;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 11890) {
                        var6 = -118764;
                    } else {
                        var6 = -135366;
                    }
                } else {
                    var6 = 136054;
                }
            } else {
                if (input[3] < 5792) {
                    if (input[0] < 24) {
                        var6 = 59266;
                    } else {
                        var6 = 136207;
                    }
                } else {
                    if (input[0] < 29) {
                        var6 = -88922;
                    } else {
                        var6 = 99246;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var6 = 136773;
            } else {
                if (input[2] < 191) {
                    var6 = -132814;
                } else {
                    var6 = 136914;
                }
            }
        } else {
            if (input[1] < 785) {
                var6 = -137178;
            } else {
                var6 = 142830;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 6000) {
                        var7 = -92060;
                    } else {
                        var7 = 47784;
                    }
                } else {
                    if (input[8] < 1516000) {
                        var7 = -132869;
                    } else {
                        var7 = 68444;
                    }
                }
            } else {
                if (input[1] < 31) {
                    if (input[1] < 24) {
                        var7 = 88265;
                    } else {
                        var7 = -121887;
                    }
                } else {
                    if (input[8] < 5346653000) {
                        var7 = 100891;
                    } else {
                        var7 = -51794;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[4] < 1) {
                    if (input[1] < 11890) {
                        var7 = -113424;
                    } else {
                        var7 = -130326;
                    }
                } else {
                    var7 = 131113;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 532413000) {
                        var7 = 131376;
                    } else {
                        var7 = -73095;
                    }
                } else {
                    if (input[3] < 11595) {
                        var7 = 129593;
                    } else {
                        var7 = -17963;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var7 = 132071;
            } else {
                if (input[2] < 191) {
                    var7 = -127552;
                } else {
                    var7 = 132021;
                }
            }
        } else {
            if (input[1] < 785) {
                var7 = -131948;
            } else {
                var7 = 135597;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 3525) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 10000) {
                        var8 = -83008;
                    } else {
                        var8 = 44027;
                    }
                } else {
                    if (input[8] < 999000) {
                        var8 = -128412;
                    } else {
                        var8 = 56200;
                    }
                }
            } else {
                if (input[3] < 37) {
                    if (input[8] < 2496250) {
                        var8 = 114169;
                    } else {
                        var8 = -55843;
                    }
                } else {
                    if (input[8] < 5346653000) {
                        var8 = 108333;
                    } else {
                        var8 = -49429;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[1] < 4164) {
                    if (input[8] < 478464540) {
                        var8 = 86175;
                    } else {
                        var8 = -339878;
                    }
                } else {
                    if (input[0] < 16) {
                        var8 = -121351;
                    } else {
                        var8 = -78209;
                    }
                }
            } else {
                if (input[3] < 5792) {
                    if (input[0] < 24) {
                        var8 = 87824;
                    } else {
                        var8 = 130576;
                    }
                } else {
                    if (input[0] < 29) {
                        var8 = -91241;
                    } else {
                        var8 = 88105;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var8 = 128103;
            } else {
                if (input[2] < 191) {
                    var8 = -123016;
                } else {
                    var8 = 127876;
                }
            }
        } else {
            if (input[1] < 785) {
                var8 = -127508;
            } else {
                var8 = 129463;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 6000) {
                        var9 = -77258;
                    } else {
                        var9 = 39203;
                    }
                } else {
                    if (input[5] < 1) {
                        var9 = -123275;
                    } else {
                        var9 = 311829;
                    }
                }
            } else {
                if (input[8] < 102000) {
                    if (input[4] < 1) {
                        var9 = 134335;
                    } else {
                        var9 = 78665;
                    }
                } else {
                    if (input[3] < 37) {
                        var9 = -33157;
                    } else {
                        var9 = 87320;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 11890) {
                        var9 = -103440;
                    } else {
                        var9 = -122473;
                    }
                } else {
                    var9 = 130295;
                }
            } else {
                if (input[3] < 5792) {
                    if (input[0] < 25) {
                        var9 = 53572;
                    } else {
                        var9 = 124054;
                    }
                } else {
                    if (input[8] < 2496250) {
                        var9 = -129235;
                    } else {
                        var9 = 84856;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var9 = 124723;
            } else {
                if (input[2] < 191) {
                    var9 = -119055;
                } else {
                    var9 = 124331;
                }
            }
        } else {
            if (input[1] < 785) {
                var9 = -123695;
            } else {
                var9 = 124179;
            }
        }
    }
    
     // Sum all the tree scores to get the raw Log-Odds
    long long total_score = var0 + var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9;
    return total_score;
}

#endif // FIREWALL_XGB_MODEL_H
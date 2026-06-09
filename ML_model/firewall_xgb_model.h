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
                        var0 = 163018;
                    } else {
                        var0 = -74516;
                    }
                } else {
                    if (input[0] < 4) {
                        var0 = -39067;
                    } else {
                        var0 = 166308;
                    }
                }
            } else {
                if (input[8] < 5348248000) {
                    if (input[3] < 37) {
                        var0 = -113001;
                    } else {
                        var0 = -175057;
                    }
                } else {
                    if (input[3] < 231) {
                        var0 = -196835;
                    } else {
                        var0 = 144061;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[4] < 1) {
                    if (input[1] < 9660) {
                        var0 = -186666;
                    } else {
                        var0 = 193208;
                    }
                } else {
                    var0 = -197037;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 538438000) {
                        var0 = -183050;
                    } else {
                        var0 = 77477;
                    }
                } else {
                    if (input[3] < 11595) {
                        var0 = -197828;
                    } else {
                        var0 = -21686;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var0 = -199993;
            } else {
                if (input[1] < 380) {
                    var0 = 185714;
                } else {
                    var0 = -198728;
                }
            }
        } else {
            if (input[1] < 781) {
                var0 = 196244;
            } else {
                var0 = -183673;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 31) {
                if (input[6] < 1) {
                    if (input[3] < 6) {
                        var1 = -96411;
                    } else {
                        var1 = 145185;
                    }
                } else {
                    if (input[0] < 4) {
                        var1 = -35175;
                    } else {
                        var1 = 150754;
                    }
                }
            } else {
                if (input[8] < 5681634300) {
                    if (input[3] < 3525) {
                        var1 = -153845;
                    } else {
                        var1 = -18525;
                    }
                } else {
                    if (input[3] < 231) {
                        var1 = -178934;
                    } else {
                        var1 = 136125;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[4] < 1) {
                    if (input[1] < 9660) {
                        var1 = -170098;
                    } else {
                        var1 = 175576;
                    }
                } else {
                    var1 = -179392;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 538438000) {
                        var1 = -166757;
                    } else {
                        var1 = 70114;
                    }
                } else {
                    if (input[3] < 11595) {
                        var1 = -179872;
                    } else {
                        var1 = -19624;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var1 = -181867;
            } else {
                if (input[1] < 380) {
                    var1 = 169461;
                } else {
                    var1 = -180808;
                }
            }
        } else {
            if (input[1] < 781) {
                var1 = 178727;
            } else {
                var1 = -168147;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 10000) {
                        var2 = 124985;
                    } else {
                        var2 = -64897;
                    }
                } else {
                    if (input[8] < 1598400) {
                        var2 = 171838;
                    } else {
                        var2 = -56191;
                    }
                }
            } else {
                if (input[3] < 23) {
                    if (input[1] < 24) {
                        var2 = -127786;
                    } else {
                        var2 = 137310;
                    }
                } else {
                    if (input[8] < 5348248000) {
                        var2 = -140092;
                    } else {
                        var2 = 51244;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[4] < 1) {
                    if (input[1] < 9660) {
                        var2 = -157277;
                    } else {
                        var2 = 162132;
                    }
                } else {
                    var2 = -166044;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 538438000) {
                        var2 = -154058;
                    } else {
                        var2 = 63608;
                    }
                } else {
                    if (input[3] < 11595) {
                        var2 = -166319;
                    } else {
                        var2 = -17762;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var2 = -168253;
            } else {
                if (input[1] < 380) {
                    var2 = 156853;
                } else {
                    var2 = -167308;
                }
            }
        } else {
            if (input[1] < 781) {
                var2 = 165451;
            } else {
                var2 = -156036;
            }
        }
    }
    
    if (input[2] < 6) {
        if (input[0] < 17) {
            if (input[1] < 11621) {
                if (input[1] < 16) {
                    if (input[3] < 6) {
                        var3 = 6068;
                    } else {
                        var3 = 146490;
                    }
                } else {
                    if (input[5] < 1) {
                        var3 = -131316;
                    } else {
                        var3 = 85906;
                    }
                }
            } else {
                if (input[4] < 1) {
                    if (input[1] < 15281) {
                        var3 = 152687;
                    } else {
                        var3 = -195320;
                    }
                } else {
                    var3 = -156140;
                }
            }
        } else {
            if (input[3] < 242) {
                if (input[0] < 25) {
                    if (input[6] < 1) {
                        var3 = 220873;
                    } else {
                        var3 = -192340;
                    }
                } else {
                    if (input[1] < 14) {
                        var3 = -196463;
                    } else {
                        var3 = -161644;
                    }
                }
            } else {
                if (input[8] < 5348248000) {
                    if (input[3] < 1027) {
                        var3 = -73261;
                    } else {
                        var3 = -156660;
                    }
                } else {
                    if (input[1] < 11890) {
                        var3 = -69263;
                    } else {
                        var3 = 155315;
                    }
                }
            }
        }
    } else {
        if (input[8] < 311236160) {
            if (input[8] < 166711250) {
                if (input[1] < 24) {
                    if (input[8] < 6000) {
                        var3 = -182694;
                    } else {
                        var3 = -172696;
                    }
                } else {
                    if (input[3] < 14) {
                        var3 = 31544;
                    } else {
                        var3 = -157813;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[0] < 4) {
                        var3 = -179635;
                    } else {
                        var3 = 135232;
                    }
                } else {
                    var3 = -158275;
                }
            }
        } else {
            if (input[1] < 31) {
                if (input[0] < 4) {
                    if (input[0] < 3) {
                        var3 = -175073;
                    } else {
                        var3 = -34798;
                    }
                } else {
                    if (input[8] < 15900000000) {
                        var3 = 163034;
                    } else {
                        var3 = 71486;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[8] < 2115563400) {
                        var3 = -40267;
                    } else {
                        var3 = -112398;
                    }
                } else {
                    if (input[2] < 187) {
                        var3 = -160985;
                    } else {
                        var3 = 120799;
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
                        var4 = 111920;
                    } else {
                        var4 = -59015;
                    }
                } else {
                    if (input[8] < 1001000) {
                        var4 = 151682;
                    } else {
                        var4 = -59666;
                    }
                }
            } else {
                if (input[1] < 31) {
                    if (input[1] < 24) {
                        var4 = -108047;
                    } else {
                        var4 = 138919;
                    }
                } else {
                    if (input[8] < 5348248000) {
                        var4 = -119876;
                    } else {
                        var4 = 46383;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 9660) {
                        var4 = -140965;
                    } else {
                        var4 = 142940;
                    }
                } else {
                    var4 = -147966;
                }
            } else {
                if (input[3] < 7215) {
                    if (input[0] < 26) {
                        var4 = -69636;
                    } else {
                        var4 = -147991;
                    }
                } else {
                    if (input[0] < 131) {
                        var4 = 8451;
                    } else {
                        var4 = -121522;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var4 = -149250;
            } else {
                if (input[1] < 380) {
                    var4 = 140101;
                } else {
                    var4 = -148683;
                }
            }
        } else {
            if (input[1] < 781) {
                var4 = 148458;
            } else {
                var4 = -146876;
            }
        }
    }
    
    if (input[2] < 6) {
        if (input[0] < 17) {
            if (input[1] < 11621) {
                if (input[1] < 16) {
                    if (input[3] < 6) {
                        var5 = 4980;
                    } else {
                        var5 = 130482;
                    }
                } else {
                    if (input[5] < 1) {
                        var5 = -114446;
                    } else {
                        var5 = 85259;
                    }
                }
            } else {
                if (input[4] < 1) {
                    if (input[3] < 4344) {
                        var5 = 188604;
                    } else {
                        var5 = 136339;
                    }
                } else {
                    var5 = -140991;
                }
            }
        } else {
            if (input[3] < 242) {
                if (input[0] < 25) {
                    if (input[6] < 1) {
                        var5 = 206987;
                    } else {
                        var5 = -170126;
                    }
                } else {
                    if (input[1] < 14) {
                        var5 = -173930;
                    } else {
                        var5 = -146065;
                    }
                }
            } else {
                if (input[8] < 5348248000) {
                    if (input[3] < 1027) {
                        var5 = -57402;
                    } else {
                        var5 = -141231;
                    }
                } else {
                    if (input[1] < 11890) {
                        var5 = -69200;
                    } else {
                        var5 = 139937;
                    }
                }
            }
        }
    } else {
        if (input[8] < 311236160) {
            if (input[8] < 151656910) {
                if (input[1] < 24) {
                    if (input[3] < 11) {
                        var5 = -154209;
                    } else {
                        var5 = -41344;
                    }
                } else {
                    if (input[3] < 14) {
                        var5 = 14369;
                    } else {
                        var5 = -142527;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[0] < 4) {
                        var5 = -159571;
                    } else {
                        var5 = 121732;
                    }
                } else {
                    var5 = -142888;
                }
            }
        } else {
            if (input[1] < 31) {
                if (input[0] < 4) {
                    if (input[0] < 3) {
                        var5 = -154655;
                    } else {
                        var5 = -21503;
                    }
                } else {
                    if (input[8] < 15900000000) {
                        var5 = 146449;
                    } else {
                        var5 = 57642;
                    }
                }
            } else {
                if (input[1] < 37) {
                    if (input[8] < 2261518600) {
                        var5 = -26196;
                    } else {
                        var5 = -108509;
                    }
                } else {
                    if (input[2] < 187) {
                        var5 = -145723;
                    } else {
                        var5 = 106390;
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
                        var6 = 101032;
                    } else {
                        var6 = -53700;
                    }
                } else {
                    if (input[8] < 1001000) {
                        var6 = 138303;
                    } else {
                        var6 = -67145;
                    }
                }
            } else {
                if (input[8] < 182815000) {
                    if (input[5] < 1) {
                        var6 = -119714;
                    } else {
                        var6 = 16059;
                    }
                } else {
                    if (input[3] < 37) {
                        var6 = 75690;
                    } else {
                        var6 = -95113;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 11890) {
                        var6 = 119065;
                    } else {
                        var6 = 135463;
                    }
                } else {
                    var6 = -136047;
                }
            } else {
                if (input[3] < 11595) {
                    if (input[0] < 26) {
                        var6 = -28994;
                    } else {
                        var6 = -134569;
                    }
                } else {
                    if (input[8] < 29212666) {
                        var6 = 132124;
                    } else {
                        var6 = -147601;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var6 = -136777;
            } else {
                if (input[1] < 380) {
                    var6 = 128196;
                } else {
                    var6 = -136426;
                }
            }
        } else {
            if (input[1] < 781) {
                var6 = 136801;
            } else {
                var6 = -140407;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 10000) {
                        var7 = 92084;
                    } else {
                        var7 = -48547;
                    }
                } else {
                    if (input[8] < 1598400) {
                        var7 = 132887;
                    } else {
                        var7 = -65816;
                    }
                }
            } else {
                if (input[8] < 2596000) {
                    if (input[2] < 1) {
                        var7 = -58316;
                    } else {
                        var7 = -143532;
                    }
                } else {
                    if (input[3] < 37) {
                        var7 = 54914;
                    } else {
                        var7 = -96637;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[4] < 1) {
                    if (input[1] < 11890) {
                        var7 = 113723;
                    } else {
                        var7 = 130443;
                    }
                } else {
                    var7 = -131105;
                }
            } else {
                if (input[0] < 26) {
                    if (input[8] < 538438000) {
                        var7 = -127493;
                    } else {
                        var7 = 82367;
                    }
                } else {
                    if (input[3] < 11595) {
                        var7 = -129705;
                    } else {
                        var7 = 15127;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var7 = -132074;
            } else {
                if (input[1] < 380) {
                    var7 = 122721;
                } else {
                    var7 = -131622;
                }
            }
        } else {
            if (input[1] < 781) {
                var7 = 131609;
            } else {
                var7 = -133499;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 3525) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 6000) {
                        var8 = 85467;
                    } else {
                        var8 = -43283;
                    }
                } else {
                    if (input[5] < 1) {
                        var8 = 127237;
                    } else {
                        var8 = -286161;
                    }
                }
            } else {
                if (input[1] < 31) {
                    if (input[1] < 24) {
                        var8 = -84638;
                    } else {
                        var8 = 119899;
                    }
                } else {
                    if (input[8] < 5681634300) {
                        var8 = -100487;
                    } else {
                        var8 = 62699;
                    }
                }
            }
        } else {
            if (input[0] < 21) {
                if (input[1] < 4418) {
                    if (input[8] < 600562300) {
                        var8 = -91524;
                    } else {
                        var8 = 339651;
                    }
                } else {
                    if (input[0] < 16) {
                        var8 = 121431;
                    } else {
                        var8 = 77740;
                    }
                }
            } else {
                if (input[3] < 5792) {
                    if (input[8] < 4635769000) {
                        var8 = -129569;
                    } else {
                        var8 = -21004;
                    }
                } else {
                    if (input[0] < 29) {
                        var8 = 89548;
                    } else {
                        var8 = -80976;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var8 = -128105;
            } else {
                if (input[1] < 380) {
                    var8 = 117924;
                } else {
                    var8 = -127550;
                }
            }
        } else {
            if (input[1] < 781) {
                var8 = 127197;
            } else {
                var8 = -127601;
            }
        }
    }
    
    if (input[2] < 14) {
        if (input[3] < 4344) {
            if (input[1] < 12) {
                if (input[3] < 6) {
                    if (input[8] < 10000) {
                        var9 = 77313;
                    } else {
                        var9 = -39829;
                    }
                } else {
                    if (input[8] < 1001000) {
                        var9 = 124601;
                    } else {
                        var9 = -65779;
                    }
                }
            } else {
                if (input[8] < 102000) {
                    if (input[4] < 1) {
                        var9 = -134163;
                    } else {
                        var9 = -81071;
                    }
                } else {
                    if (input[3] < 37) {
                        var9 = 32965;
                    } else {
                        var9 = -87204;
                    }
                }
            }
        } else {
            if (input[0] < 22) {
                if (input[4] < 1) {
                    if (input[1] < 11890) {
                        var9 = 103776;
                    } else {
                        var9 = 122593;
                    }
                } else {
                    var9 = -130278;
                }
            } else {
                if (input[3] < 7215) {
                    if (input[0] < 26) {
                        var9 = -42212;
                    } else {
                        var9 = -122927;
                    }
                } else {
                    if (input[0] < 93) {
                        var9 = 59966;
                    } else {
                        var9 = -75921;
                    }
                }
            }
        }
    } else {
        if (input[2] < 356) {
            if (input[2] < 187) {
                var9 = -124724;
            } else {
                if (input[1] < 380) {
                    var9 = 113658;
                } else {
                    var9 = -124065;
                }
            }
        } else {
            if (input[1] < 781) {
                var9 = 123404;
            } else {
                var9 = -122491;
            }
        }
    }
    
     // Sum all the tree scores to get the raw Log-Odds
    long long total_score = var0 + var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9;
    return total_score;
}

#endif // FIREWALL_XGB_MODEL_H
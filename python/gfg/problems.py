def numberOfSubsequences (S,W):
    # code here 
# code here 
    index=0
    len_s=len(S)
    len_w=len(W)
    occurences=0
    while index < len_s:
        #print(i)
        j = 0
        while j < len_w:            
            if index>=len_s:
                break
            
            if W[j] == S[index]:
                print("print:" + str(index) + "=>" + str(W[j]) + "=>" + str(S[index]))
                j=j+1
                index=index+1
                continue
            index=index+1
        if j >= len_w:
            occurences=occurences+1    
    return occurences

print("hello..")
S="keptbugeylznkshjclmjrqmgnuenwjqgpibqckxcvwrhobstoecfwoljjszhdrptzrlediiagchxdcqrisyfilordpajhqegjpmmyvogxxdczttkntpwefpkvqtcgxkrmzfmwtvvqyxqusahlrdrwvbrluvttikihrwdkraasxsmputclztkuxdhrbcnjovsftxpnxrfukrlempsliehfhqzisotglllekarhswdepqkcfepqizvqpwaimuoxhcesevzyufclvpnbtfrceouvnudzquxyydqcyrbuwfguuvvoaosgcmcrghrxbqxbtpetghqfmybjtyxwmpeqdgijobirtftouzhdgzkuxldtjcpxttnwcxgqaqjtwehsdrxlqhgquljfoycht"
W="kept"
occur=numberOfSubsequences(S, W)
print (occur)
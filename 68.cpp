class Solution {


public:
int findLineEndIndex (int index, const vector<string>&words, int maxWidth)
{   
    int endIndex = index;
    stringstream temp;
    temp<<words[index];
    for (int i = index+1;i<words.size();i++ )
    {
        if((temp.str().size()+words[i].size()+1)<=maxWidth)
        {
            temp<<" "<<words[i];
            endIndex = i;
        }
        else 
            break;
    }
    // cout<<temp.str()<<endl;
    return endIndex ;
}   


    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        stringstream ss;
        for (int i =0 ;i<words.size();)
        {
            int lineEndIndex = findLineEndIndex(i, words, maxWidth);
            // cout<<lineEndIndex<<" ";
            if(lineEndIndex ==words.size()-1)
            {
                string tempAdd =words[i];
                for (int k = i+1;k<=lineEndIndex;k++)
                    tempAdd=tempAdd+" "+words[k];

                // tempAdd.push_back('.');
                int left = maxWidth-tempAdd.size();
                while(left>0)
                {
                    tempAdd.push_back(' ');
                    left--;
                }
                output.push_back(tempAdd);
                break;
            }
            
            int charCount = 0;
            for (int j = i;j<=lineEndIndex;j++)
            {
                charCount+=words[j].size();
                // cout<<words[j]<<" ";
            }
            // cout<<endl;
            // cout<<charCount<<" ";
            cout<<"i:"<<i<<" lineEndindx:"<<lineEndIndex<<" ";
            int numWords = lineEndIndex-i;
            // cout<<"numWords:"<<numWords<<" ";/
            int space = maxWidth -charCount;
            // cout<<"space : "<<space<<" ";
            int minGap;
            if(numWords!=0)
             minGap = space/numWords;
            else 
            minGap = space;
            // cout<<minGap<<" ";
            string minGapStr = "";
            while(minGap>0)
            {
                minGapStr.push_back(' ');
                minGap--;
            }
            int leftGapCount = 0;
            if(numWords!=0)
             leftGapCount = space%numWords;
            string tempAdd = words[i];

            if(numWords ==0)
                tempAdd.append(minGapStr);
            
            for (int k = i+1;k<=lineEndIndex;k++)
            {   
                tempAdd.append(minGapStr);

                if(leftGapCount>0)
                {
                    tempAdd.push_back(' ');
                    leftGapCount--;
                }
                tempAdd.append(words[k]);
            }
            output.push_back(tempAdd);
            i=lineEndIndex+1;
        }

        return output;
    }
};
setwd("~/ACSAI-Notes/Y2S2/DATA2")
getwd()
load("datasets/PIXAR/posts_disneypixar.rdata")

install.packages("SnowballC")

library(tm)
library(SnowballC)

# import data
str(posts)
texts <- posts$message
head(texts, n = 60)

# change encoding (this will fail on emojis)
texts <- iconv(texts, "UTF-8", "ASCII")

# putting all in the corpus 
corpus <- Corpus(VectorSource(texts))
head(summary(corpus))
inspect(corpus[580])

# output as string some entry of the corpus
writeLines(as.character(corpus[510]))
# get a list of standard transformations
# stemming is removing all but the root from a word
getTransformations()

# make some custom transform
toSpace <- content_tranformer(function(x, pattern) {return (gsub(pattern, " ", x))})
# apply
corpus <- tm_map(corpus, toSpace, "-")
corpus <- tm_map(corpus, toSpace, ":")

# Some classic preprocessing

# Convert the text to lower case
corpus <- tm_map(corpus, content_transformer(tolower))
writeLines(as.character(corpus[[560]]))

# Remove numbers
corpus <- tm_map(corpus, removeNumbers)
writeLines(as.character(corpus[[560]]))

# Remove English common stopwords
corpus <- tm_map(corpus, removeWords, stopwords("english"))
writeLines(as.character(corpus[[560]]))

# Remove punctuations
corpus <- tm_map(corpus, removePunctuation)
writeLines(as.character(corpus[[565]]))

# Eliminate extra white spaces
corpus <- tm_map(corpus, stripWhitespace)

# DOCUMENT TERM MATRIX (sound cool)
dtm = DocumentTermMatrix(corpus)

# sum the frequencies of single words
freq <- colSums(as.matrix(dtm))
freq[35:40]

# sort em
ord <- order(freq, decreasing = TRUE)

# wtf is this syntax? <---------------------
# Inspect most frequently occurring terms
freq[head(ord)]
# Inspect least frequently occurring terms
freq[tail(ord)]

# filter with lowerbounds on the frequencies
findFreqTerms(dtm, lowfreq = 10)

# graph
wf = data.frame(word = names(freq), # names() allows to get or set the names of an object
                freq = freq)
head(wf)

library(ggplot2)
ggplot(subset(wf, freq>10), aes(x = reorder(word, -freq), y = freq)) +
  geom_bar(stat = "identity") + 
  labs(x = "", y = "frequency") +
  theme(axis.text.x=element_text(angle=45, hjust=1))

# Cool stuff that people like
library(wordcloud)
wordcloud(wf$word, wf$freq, 
          min.freq = 10, 
          rot.per = 0.15, 
          colors = brewer.pal(8, "Dark2")
)
library(wordcloud)
wordcloud(wf$word, wf$freq, 
          scale=c(5,0.5), min.freq = 5, 
          random.order = F, 
          rot.per = 0.15, 
          colors = brewer.pal(8, "Spectral")
)

# get sentiment
library('syuzhet')
sentiment = get_nrc_sentiment(texts)
td = data.frame(t(sentiment))
td[,1:5]

# transformation and cleaning

# Compute column sums across rows for each level of a grouping variable
td = data.frame(rowSums(td[-1]))
td

names(td)[1] <- "count"
td

rownames(tdw) <- NULL
tdw

# results!
td_em  = tdw[1:8, ] # emotions
td_pol = tdw[9:10, ] # polarity

require("ggplot2")
ggplot(td_em, aes(x = sentiment, y = count, fill = sentiment)) +
  geom_bar(stat = "identity") +
  labs(x = "emotion") +
  theme(axis.text.x=element_text(angle=45, hjust=1), legend.title = element_blank())








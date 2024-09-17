mkdir build                                                                                            
pdflatex --output-directory=build 1_intro.tex
find build -type f ! -name "*.pdf" -delete

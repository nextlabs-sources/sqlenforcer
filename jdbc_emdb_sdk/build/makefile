fqdn=com/nextlabs/EMDB
srcdir=src/${fqdn}
BINDIR=bin
jarname=emdb1.3.jar
SRC=$(wildcard  ${srcdir}/*.java)

classes = $(addprefix $(BINDIR)/$(fqdn)/, $(addsuffix .class, $(basename $(notdir $(SRC)))))

#jc="C:/Program Files/Java/jdk-10.0.2/bin/javac"
jc="C:/Program Files/Java/jdk1.8.0_201/bin/javac" 

./bin/$(jarname):${SRC}
	@if [ ! -d $(BINDIR) ] ; then \
		mkdir -p $(BINDIR) ; \
	fi
	${jc} -d $(BINDIR)  ${SRC}
	cd $(BINDIR) && jar -cvf  $(jarname)  com

versioninfo:

clean:
	rm -rf $(BINDIR)
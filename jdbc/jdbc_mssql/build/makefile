fqdn=com/nextlabs/jdbc/mssqlproxy
srcdir=src/${fqdn}
BINDIR=bin
jarname=mssql-jdbc.jar
SRC=$(wildcard  ${srcdir}/*.java)

classes = $(addprefix $(BINDIR)/$(fqdn)/, $(addsuffix .class, $(basename $(notdir $(SRC)))))

#jc="C:/Program Files/Java/jdk-10.0.2/bin/javac"
jc="C:/Program Files/Java/jdk1.8.0_201/bin/javac" 

./bin/$(jarname):${SRC}
	@if [ ! -d $(BINDIR) ] ; then \
		mkdir -p $(BINDIR) ; \
	fi
	${jc} -d $(BINDIR)  ${SRC}
	cp -rfu META-INF $(BINDIR)/   
	cd $(BINDIR) && jar -cvf  $(jarname) META-INF/* com



clean:
	rm -rf $(BINDIR)

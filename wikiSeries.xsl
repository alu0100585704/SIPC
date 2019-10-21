<?xml version='1.0' ?> 
<xsl:stylesheet version="1.1" 
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"> 
  <xsl:template match="/"> 
   <HTML> 
    <BODY> 
     <B> Notas del examen del 6 de Septiembre de 2005 
</B> 
     <BR/> 
     <BR/> 
     <TABLE> 
	<xsl:apply-templates select="CLASE/ALUMNO"/>

<!--      <xsl:for-each  select="CLASE[@CURSO='5']/ALUMNO[NOTA&lt;5]"> 
      <xsl:sort order="ascending" select="APELLIDOS"/> 
       <TR> 
        <TD><xsl:value-of select="APELLIDOS"/>, <xsl:value-of select="NOMBRE"/></TD> 
        <TD><B><xsl:value-of select="NOTA"/></B></TD> 
        <BR></BR> 
       </TR> 
      </xsl:for-each>  -->


     </TABLE> 
    </BODY> 
   </HTML> 
  </xsl:template> 

<xsl:template match="ALUMNO">
      <TR> 
        <TD><xsl:value-of select="APELLIDOS"/>, <xsl:value-of select="NOMBRE"/></TD> 
        <TD><B><xsl:value-of select="NOTA"/></B></TD> 
        <BR></BR> 
       </TR> 
</xsl:template>

 </xsl:stylesheet> 



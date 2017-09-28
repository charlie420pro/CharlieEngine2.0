struct PS_INPUT
{
    float4 m_Position : SV_POSITION;
    float2 m_TexCoord : TEXCOORD;
    float3 m_Normals : NORMAL;
};

SamplerState Sampler : register(s0);
Texture2D<float4> Diffuse : register(t0);


cbuffer cbLight : register(b0)
{
    float3 m_LightPosition;
    float4 m_Color;
}


float4 PSMain(PS_INPUT Input) : SV_Target
{

    float4 f4DiffuseColor = Diffuse.Sample(Sampler,Input.m_TexCoord);
    float3 f3LightDir = normalize(Input.m_Position.xyz - m_LightPosition);
    float fIncidence = saturate(dot(Input.m_Normals, f3LightDir));

    float3 f3SpecularColor = float3(1.0f,1.0f,1.0f);
   
    f4DiffuseColor = pow(f4DiffuseColor, 2.2f);
   
   
    float3 f3FinalColor = f4DiffuseColor.xyz * fIncidence * f3SpecularColor;
    f3FinalColor = pow(f3FinalColor, 1.0f / 2.2f);
   
    return float4(f3FinalColor, 1);
}




struct PS_INPUT
{
    float4 m_Position : SV_POSITION;
    float2 m_TexCoord : TEXCOORD;
    float3 m_Normals : NORMAL;
};

SamplerState Sampler : register(s0);
Texture2D<float4> Diffuse : register(t0);



///////////////////////////////////////////////////

////-------------------------------------------////



cbuffer cbLight : register(b0)
{
    float3 m_lightPosition;
    float m_Scale;
    float m_Bias;
    float m_Intensity;
    float m_SampleRadius;
    float4 ClearColor;
}


float4 PSMain(PS_INPUT input) : SV_Target
{

    float3 Position = input.m_Position;
    float3 Normal = input.m_Normals;
    float3 DiffuseColor = Diffuse.Sample(Sampler,input.m_TexCoord);
    float3 SpecularColor = float3(1,1,1);
   
    DiffuseColor = pow(DiffuseColor, 2.2f);
   
    float3 lightDir = normalize(Position - m_lightPosition);
    float incidence = saturate(dot(Normal, lightDir));
   
    float3 FinalColor = DiffuseColor * incidence * SpecularColor;
    FinalColor = pow(FinalColor, 1.0f / 2.2f);
   
    return float4(FinalColor, 1);
}



